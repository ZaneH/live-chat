#include <boost/algorithm/string.hpp>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <zmqpp/zmqpp.hpp>

int main() {
    zmqpp::context context;
    zmqpp::socket server(context, zmqpp::socket_type::router);
    server.bind("tcp://*:4242");

    std::unordered_set<std::string> clientIds;

    std::cout << "Listening...\n";

    while (true) {
        zmqpp::message msg;
        server.receive(msg);

        std::string fromId;
        std::string cmd;
        std::string displayName, room, body;

        msg >> fromId;
        msg >> cmd;

        if (cmd == "HELLO") {
            clientIds.insert(fromId);
            continue;
        }

        msg >> displayName >> room >> body;

        // Broadcast to all clients
        for (const auto &toId : clientIds) {
            if (toId == fromId) {
                continue;
            }

            zmqpp::message txMsg(toId, displayName, room, body);
            server.send(txMsg);
        }
    }

    return 0;
}
