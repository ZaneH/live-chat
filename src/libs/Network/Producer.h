#pragma once
#include <QObject>
#include <QString>
#include <zmqpp/zmqpp.hpp>

using namespace std;

class Message;

class Producer : public QObject {
  Q_OBJECT

public:
  Producer(zmqpp::context *ctx, string topic);

private:
  string m_topic;
  zmqpp::socket m_socket;
  zmqpp::context *m_context;

public slots:
  void run();
  void sendMessage(QString body);
};
