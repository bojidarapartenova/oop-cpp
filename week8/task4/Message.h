#include <string>
#include <compare>
#include <ostream>

class Message
{
private:
    std::string sender;
    std::string content;
    long timestamp;

public:
    Message(const std::string &sender_, const std::string &content_, long timestamp_);

    const std::string &getSender() const;
    long getTimestamp() const;

    auto operator<=>(const Message &other) const
    {
        return timestamp <=> other.timestamp;
    }

    friend std::ostream &operator<<(std::ostream &, const Message &);
};