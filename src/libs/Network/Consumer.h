#pragma once
#include <QDebug>
#include <QObject>
#include <QThread>
#include <zmqpp/zmqpp.hpp>

class Consumer : public QObject {
    Q_OBJECT

public slots:
    void run();
};
