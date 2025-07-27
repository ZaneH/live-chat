#pragma once
#include <QWidget>
#include <QThread>

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

private:
    QTextEdit *chatLog;
    QTextEdit *messageBox;
    QPushButton *sendButton;
};
