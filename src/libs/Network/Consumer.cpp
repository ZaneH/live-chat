#include "Consumer.h"
#include "../libs/Models/Message.h"
#include <QDebug>
#include <QString>

Consumer::Consumer(zmqpp::context *ctx, std::string topic)
    : m_context(ctx), m_topic(topic),
      m_socket(*ctx, zmqpp::socket_type::dealer) {}

void Consumer::run() {
  m_socket.connect("tcp://0.0.0.0:4242");

  // Inform router of dealer's presense
  zmqpp::message hello("HELLO");
  m_socket.send(hello);

  do {
    zmqpp::message message;
    m_socket.receive(message);
    std::string displayName, room, body;
    message >> displayName >> room >> body;

    Message msg(displayName, room, body);
    emit messageRecieved(&msg);
  } while (1);
}
