#pragma once
#include <string>
#include <QString>

class Message {
public:
        Message(std::string username, std::string text);
        std::string getUsername();
        std::string getText();
private:
        std::string m_username;
        std::string m_text;
};
