#pragma once
#include <QPushButton>
#include <QTextEdit>
#include <QThread>
#include <QWidget>

class Message;

class ChatWindow : public QWidget {
  Q_OBJECT
  QThread consumerThread;

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
};
