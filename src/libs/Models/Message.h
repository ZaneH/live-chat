#pragma once
#include <QString>
#include <string>

class Message {
public:
  Message(std::string username, std::string text);
  std::string getUsername();
  std::string getText();

private:
  std::string m_username;
  std::string m_text;
};
