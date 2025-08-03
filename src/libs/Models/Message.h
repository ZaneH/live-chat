#pragma once
#include <QObject>
#include <QString>
#include <string>

class Message : public QObject {
  Q_OBJECT

public:
  Message(std::string displayName, std::string room, std::string body,
          QObject *parent = nullptr);
  std::string getDisplayName();
  std::string getRoom();
  std::string getBody();

private:
  std::string m_displayName;
  std::string m_room;
  std::string m_body;
};
