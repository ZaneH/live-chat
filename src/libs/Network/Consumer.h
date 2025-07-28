#pragma once
#include <QDebug>
#include <QObject>
#include <QThread>
#include <zmqpp/zmqpp.hpp>

class Message;

class Consumer : public QObject {
  Q_OBJECT

signals:
  void messageRecieved(Message *message);

public slots:
  void run();
};
