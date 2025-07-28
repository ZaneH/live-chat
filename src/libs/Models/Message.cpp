#include "Message.h"
#include <string>

Message::Message(std::string username, std::string text) {
  m_username = username;
  m_text = text;
}

std::string Message::getText() { return m_text; }

std::string Message::getUsername() { return m_username; }
