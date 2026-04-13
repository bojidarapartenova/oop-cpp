#include <string>

class Task
{
private:
    std::string title;
    std::string description;
    int priority;
    bool completed;

public:
    Task(const std::string &title_, const std::string &desc, int priority_);

    void markDone();
    bool isCompleted() const;
    int getPriority() const;
    const std::string &getTitle() const;

    std::strong_ordering operator<=>(const Task &other) const
    {
        if (auto cmp = priority <=> other.priority; cmp != 0)
        {
            return cmp;
        }
        return std::compare_strong_order_fallback(title, other.title);
    }

    friend std::ostream &operator<<(std::ostream &, const Task &);
};