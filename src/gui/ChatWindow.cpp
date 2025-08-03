#include "ChatWindow.h"
#include "../libs/Network/Consumer.h"
#include "../libs/Network/Producer.h"
#include <QDebug>
#include <QFontMetrics>
#include <QHBoxLayout>
#include <QObject>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>
#include <QVBoxLayout>

ChatWindow::ChatWindow(QWidget *parent)
    : QWidget(parent), displayName("Anonymous") {
  auto *mainLayout = new QVBoxLayout(this);

  chatLog = new QTextEdit(this);
  chatLog->setReadOnly(true);
  mainLayout->addWidget(chatLog, 1);

  auto *bottomLayout = new QHBoxLayout();

  messageBox = new MyTextEdit(this);
  messageBox->setFixedHeight(messageBox->fontMetrics().lineSpacing() * 2);
  messageBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
  messageBox->setAcceptRichText(false);
  connect(messageBox, &QTextEdit::textChanged, this,
          &ChatWindow::adjustTextEditHeight);
  connect(messageBox, &MyTextEdit::submitted, this, &ChatWindow::sendMessage);

  sendButton = new QPushButton("Send", this);
  connect(sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);

  bottomLayout->addWidget(messageBox);
  bottomLayout->addWidget(sendButton);

  mainLayout->addLayout(bottomLayout);
  setLayout(mainLayout);

  createClient("room");
  createConsumer("room");
}

void ChatWindow::createClient(std::string topic) {
  producer = new Producer(&context, topic);
  producer->moveToThread(&producerThread);
  connect(&producerThread, &QThread::started, producer, &Producer::run);

  producerThread.start();
}

void ChatWindow::createConsumer(std::string topic) {
  consumer = new Consumer(&context, topic);
  consumer->moveToThread(&consumerThread);
  connect(&consumerThread, &QThread::started, consumer, &Consumer::run);
  connect(consumer, &Consumer::messageRecieved, this, &ChatWindow::addMessage);

  consumerThread.start();
}

void ChatWindow::sendMessage() {
  QString body = messageBox->toPlainText();

  Message msg(displayName, "room", body.toStdString());

  std::string bs = body.toStdString();
  int pos = bs.find("/nick ");
  if (pos == 0) {
    std::string nick = bs.substr(strlen("/nick "));
    displayName = nick;
    messageBox->setPlainText("");

    return;
  }

  producer->sendMessage(&msg);

  messageBox->setPlainText("");
}

void ChatWindow::adjustTextEditHeight() {
  int maxHeight = fontMetrics().lineSpacing() * 5;
  int docHeight = messageBox->document()->size().height();
  int newHeight = qMin(maxHeight, int(docHeight) + 10);
  messageBox->setFixedHeight(newHeight);
}

void ChatWindow::addMessage(Message *message) {
  QString newText = chatLog->toPlainText();
  QString newLine = QString::fromStdString(
      std::format("{}: {}\n", message->getDisplayName(), message->getBody()));
  newText.append(newLine);
  chatLog->setText(newText);
}
