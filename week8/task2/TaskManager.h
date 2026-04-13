#include "Task.h"
#include <vector>
#include <optional>

class TaskManager
{
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task &t);
    void removeCompleted();
    std::vector<Task> getCompleted() const;
    std::vector<Task> getPending() const;
    std::vector<Task> filterByPriority(int minPriority) const;
    void sortByPriority();
    std::optional<Task> findMostImportant() const;
    void printAll() const;

    explicit operator bool() const;
};