#include "Consumer.h"
#include <QDebug>

using namespace std;

void Consumer::run() {
  qInfo() << "Constructed";

  const string endpoint = "tcp://*:4242";

  zmqpp::context context;

  zmqpp::socket_type type = zmqpp::socket_type::pull;
  zmqpp::socket socket(context, type);

  socket.bind(endpoint);

  zmqpp::message message;
  socket.receive(message);
  string text;
  message >> text;

  qInfo() << "Received: " << text;
}
