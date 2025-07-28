#include "Message.h"
#include <string>

Message::Message(std::string displayName, std::string text) {
  m_displayName = displayName;
  m_text = text;
}

std::string Message::getBody() { return m_text; }

std::string Message::getDisplayName() { return m_displayName; }
