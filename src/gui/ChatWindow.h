#pragma once
#include <QWidget>
#include <QThread>
#include "../libs/Models/Message.h"

class QTextEdit;
class QPushButton;

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
