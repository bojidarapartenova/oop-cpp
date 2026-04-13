#include "Message.h"
#include <fstream>

Message::Message(const std::string &sender_, const std::string &content_, long timestamp_) : sender(sender_), content(content_), timestamp(timestamp_) {}

const std::string &Message::getSender() const
{
    return sender;
}

long Message::getTimestamp() const
{
    return timestamp;
}

std::ostream &operator<<(std::ostream &os, const Message &m)
{
    os << "Sender: " << m.sender << " Content: " << m.content << " Timestamp: " << m.timestamp;
    return os;
}
