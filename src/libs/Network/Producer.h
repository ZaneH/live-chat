#pragma once
#include "../Models/Message.h"
#include <QObject>
#include <QString>
#include <zmqpp/zmqpp.hpp>

class Message;

class Producer : public QObject {
  Q_OBJECT

public:
  Producer(zmqpp::context *ctx, std::string topic);

private:
  std::string m_topic;
  zmqpp::socket m_socket;
  zmqpp::context *m_context;

public slots:
  void run();
  void sendMessage(Message *message);
};
