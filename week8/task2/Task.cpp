#include "Task.h"
#include <fstream>

Task::Task(const std::string &title_, const std::string &desc, int priority_) : title(title_), description(desc), priority(priority_), completed(false) {}

void Task::markDone()
{
    completed = true;
}

bool Task::isCompleted() const
{
    return completed;
}

int Task::getPriority() const
{
    return priority;
}

const std::string &Task::getTitle() const
{
    return title;
}

std::ostream &operator<<(std::ostream &os, const Task &t)
{
    os << "Title: " << t.title << " Description: " << t.description << " Priority: " << t.priority << " Is Completed: " << t.completed;

    return os;
}
