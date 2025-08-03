#pragma once
#include <QObject>
#include <QTextEdit>

class MyTextEdit : public QTextEdit {
    Q_OBJECT

  public:
    MyTextEdit(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;

  private:
  signals:
    void submitted();
};
