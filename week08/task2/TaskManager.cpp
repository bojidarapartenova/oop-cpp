#include "TaskManager.h"
#include <algorithm>
#include <iostream>
#include <print>

void TaskManager::addTask(const Task &t)
{
    tasks.push_back(t);
}

void TaskManager::removeCompleted()
{
    std::erase_if(tasks, [&](const Task &t)
                  { return t.isCompleted(); });
}

std::vector<Task> TaskManager::getCompleted() const
{
    std::vector<Task> result;
    for (const auto &t : tasks)
    {
        if (t.isCompleted())
        {
            result.push_back(t);
        }
    }
    return result;
}

std::vector<Task> TaskManager::getPending() const
{
    std::vector<Task> result;
    for (const auto &t : tasks)
    {
        if (!t.isCompleted())
        {
            result.push_back(t);
        }
    }
    return result;
}

std::vector<Task> TaskManager::filterByPriority(int minPriority) const
{
    std::vector<Task> result;
    for (const auto &t : tasks)
    {
        if (t.getPriority() >= minPriority)
        {
            result.push_back(t);
        }
    }
    return result;
}

void TaskManager::sortByPriority()
{
    std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
              { return a.getPriority() > b.getPriority(); });
}

std::optional<Task> TaskManager::findMostImportant() const
{
    if (tasks.empty())
    {
        return std::nullopt;
    }

    return *std::max_element(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
                             { return a.getPriority() < b.getPriority(); });
}

void TaskManager::printAll() const
{
    std::print("Tasks:\n");
    for (const auto &t : tasks)
    {
        std::print("Title: {}, Priority: {}, Is Completed: {}\n", t.getTitle(), t.getPriority(), t.isCompleted());
    }
}

TaskManager::operator bool() const
{
    return tasks.size() > 0 &&
           std::count_if(tasks.begin(), tasks.end(),
                         [](const Task &t)
                         { return !t.isCompleted(); }) > tasks.size() / 2;
}
