#include "Message.h"
#include <vector>
#include <optional>

class Chat
{
private:
    std::vector<Message> messages;

public:
    void sendMessage(const Message &m);
    std::vector<Message> getMessagesFrom(const std::string &sender) const;
    std::vector<Message> getMessagesInRange(long from, long to) const;
    void deleteMessagesFrom(const std::string &sender);
    void sortByTime();
    std::optional<Message> latestMessage() const;
    void print() const;
};