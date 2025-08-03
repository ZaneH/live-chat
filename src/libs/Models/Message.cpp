#include "Message.h"
#include <format>
#include <string>

Message::Message(std::string displayName, std::string room, std::string body,
                 QObject *parent)
    : QObject(parent), m_displayName(displayName), m_room(room), m_body(body) {}

std::string Message::getBody() { return m_body; }

std::string Message::getRoom() { return m_room; }

std::string Message::getDisplayName() { return m_displayName; }
