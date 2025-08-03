#pragma once
#include <QDebug>
#include <QObject>
#include <QThread>
#include <zmqpp/zmqpp.hpp>

class Message;

class Consumer : public QObject {
  Q_OBJECT

public:
  Consumer(zmqpp::context *ctx, std::string topic);

private:
  std::string m_topic;
  zmqpp::socket m_socket;
  zmqpp::context *m_context;

signals:
  void messageRecieved(Message *message);

public slots:
  void run();
};
