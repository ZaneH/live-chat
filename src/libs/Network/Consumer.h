#pragma once
#include <QDebug>
#include <QObject>
#include <QThread>
#include <zmqpp/zmqpp.hpp>
#include "../libs/Models/Message.h"

class Consumer : public QObject {
    Q_OBJECT

signals:
    void messageRecieved(Message *message);

public slots:
    void run();
};
