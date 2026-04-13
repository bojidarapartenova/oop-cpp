#include "Chat.h"
#include <algorithm>
#include <print>

void Chat::sendMessage(const Message &m)
{
    messages.push_back(m);
}

std::vector<Message> Chat::getMessagesFrom(const std::string &sender) const
{
    std::vector<Message> result;
    for (const auto &m : messages)
    {
        if (m.getSender() == sender)
        {
            result.push_back(m);
        }
    }
    return result;
}

std::vector<Message> Chat::getMessagesInRange(long from, long to) const
{
    std::vector<Message> result;
    for (const auto &m : messages)
    {
        if (m.getTimestamp() >= from && m.getTimestamp() <= to)
        {
            result.push_back(m);
        }
    }
    return result;
}

void Chat::deleteMessagesFrom(const std::string &sender)
{
    std::erase_if(messages, [&](const Message &m)
                  { return m.getSender() == sender; });
}

void Chat::sortByTime()
{
    std::sort(messages.begin(), messages.end(), [](const Message &a, const Message &b)
              { return a.getTimestamp() < b.getTimestamp(); });
}

std::optional<Message> Chat::latestMessage() const
{
    if (messages.empty())
    {
        return std::nullopt;
    }
    return *std::max_element(messages.begin(), messages.end(), [](const Message &a, const Message &b)
                             { return a.getTimestamp() < b.getTimestamp(); });
}

void Chat::print() const
{
    std::print("Messages:\n");
    for (const auto &m : messages)
    {
        std::print("Sender: {}, Timestamp: {}\n", m.getSender(), m.getTimestamp());
    }
}
