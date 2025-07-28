#pragma once
#include <QString>
#include <string>

class Message {
public:
  Message(std::string username, std::string text);
  std::string getDisplayName();
  std::string getBody();

private:
  std::string m_displayName;
  std::string m_text;
};
