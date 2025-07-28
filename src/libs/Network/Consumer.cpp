#include "Consumer.h"
#include "../libs/Models/Message.h"
#include <QDebug>
#include <QString>

Consumer::Consumer(zmqpp::context *ctx, string topic)
    : m_context(ctx), m_topic(topic), m_socket(*ctx, zmqpp::socket_type::sub) {}

void Consumer::run() {
  m_socket.connect("tcp://0.0.0.0:4242");
  qInfo() << "Listening to topic:" << m_topic;
  m_socket.subscribe(m_topic);

  do {
    zmqpp::message message;
    m_socket.receive(message);
    string room;
    string body;
    message >> room;
    message >> body;

    Message *m = new Message(room, body);
    qInfo() << room << body;
    emit messageRecieved(m);
  } while (1);
}
