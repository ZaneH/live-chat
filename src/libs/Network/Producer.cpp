#include "Producer.h"
#include <QDebug>

Producer::Producer(zmqpp::context *ctx, string topic)
    : m_context(ctx), m_topic(topic), m_socket(*ctx, zmqpp::socket_type::pub) {}

void Producer::run() { m_socket.bind("tcp://*:4242"); }

void Producer::sendMessage(QString body) {
    zmqpp::message message(m_topic, body.toStdString());
    qInfo() << "Sending message" << m_topic << body;
    m_socket.send(message);
}
