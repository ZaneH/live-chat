#pragma once
#include <QString>
#include <string>

class Message {
public:
  Message(std::string username, std::string room, std::string body);
  std::string getDisplayName();
  std::string getRoom();
  std::string getBody();

private:
  std::string m_displayName;
  std::string m_room;
  std::string m_body;
};
