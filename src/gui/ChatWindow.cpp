#include "ChatWindow.h"
#include <QVBoxLayout>
#include <QThread>
#include <QObject>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QFontMetrics>
#include <QDebug>
#include <string>
#include "../libs/Network/Consumer.h"

ChatWindow::ChatWindow(QWidget *parent) : QWidget(parent) {
    auto *mainLayout = new QVBoxLayout(this);

    chatLog = new QTextEdit(this);
    chatLog->setReadOnly(true);
    mainLayout->addWidget(chatLog, 1);

    auto *bottomLayout = new QHBoxLayout();

    messageBox = new QTextEdit(this);
    messageBox->setFixedHeight(messageBox->fontMetrics().lineSpacing() * 2);
    messageBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    messageBox->setAcceptRichText(false);
    connect(messageBox, &QTextEdit::textChanged, this, &ChatWindow::adjustTextEditHeight);

    sendButton = new QPushButton("Send", this);
    connect(sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);

    bottomLayout->addWidget(messageBox);
    bottomLayout->addWidget(sendButton);

    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    // Add chat consumer
    auto consumer = new Consumer();
    consumer->moveToThread(&consumerThread);
    QObject::connect(&consumerThread, &QThread::started, consumer, &Consumer::run);
    QObject::connect(consumer, &Consumer::messageRecieved, this, &ChatWindow::addMessage);
    consumerThread.start();
}

void ChatWindow::sendMessage() {
    qInfo() << "Hi";
}

void ChatWindow::adjustTextEditHeight() {
    int maxHeight = fontMetrics().lineSpacing() * 5;
    int docHeight = messageBox->document()->size().height();
    int newHeight = qMin(maxHeight, int(docHeight) + 10);
    messageBox->setFixedHeight(newHeight);
}

void ChatWindow::addMessage(Message *message) {
    QString newText = chatLog->toPlainText();
    QString newLine = QString::fromStdString(std::format("{}: {}\n", message->getUsername(), message->getUsername()));
    newText.append(newLine);
    chatLog->setText(newText);
}
