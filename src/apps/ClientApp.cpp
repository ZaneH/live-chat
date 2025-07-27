#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "../gui/ChatWindow.h"

int main(int argc, char *argv[]) {
  QApplication app (argc, argv);

  ChatWindow window;
  window.resize(375, 300);
  window.setMinimumSize(375, 300);
  window.setWindowTitle("Chat");
  window.show();

  return app.exec();
}
