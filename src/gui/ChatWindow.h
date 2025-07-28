#pragma once
#include "../libs/Models/Message.h"
#include "../libs/Network/Consumer.h"
#include "../libs/Network/Producer.h"
#include <QPushButton>
#include <QTextEdit>
#include <QThread>
#include <QWidget>

class ChatWindow : public QWidget {
  Q_OBJECT
  QThread consumerThread;
  QThread producerThread;

public:
  ChatWindow(QWidget *parent = nullptr);

private slots:
  void sendMessage();
  void adjustTextEditHeight();
  void addMessage(Message *message);

private:
  QTextEdit *chatLog;
  QTextEdit *messageBox;
  QPushButton *sendButton;

  zmqpp::context context;
  Consumer *consumer;
  Producer *producer;

  void addMessageListener(std::string topic);
  void addPublisher(std::string topic);
};
