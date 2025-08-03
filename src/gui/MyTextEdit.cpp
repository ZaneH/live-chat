#include "MyTextEdit.h"
#include <QKeyEvent>
#include <QWidget>

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {}

void MyTextEdit::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return) {
        emit submitted();
    } else {
        QTextEdit::keyPressEvent(event);
    }
}
