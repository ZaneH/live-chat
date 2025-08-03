#include "Producer.h"
#include <QDebug>

Producer::Producer(zmqpp::context *ctx, std::string topic)
    : m_context(ctx), m_topic(topic),
      m_socket(*ctx, zmqpp::socket_type::dealer) {}

void Producer::run() { m_socket.connect("tcp://127.0.0.1:4242"); }

void Producer::sendMessage(Message *message) {
  zmqpp::message msg("MESSAGE", message->getDisplayName(), message->getRoom(),
                     message->getBody());
  m_socket.send(msg);
}
