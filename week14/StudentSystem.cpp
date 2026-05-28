#include "StudentSystem.h"
#include <algorithm>

StudentSystem::StudentSystem(std::vector<Student> students, std::shared_ptr<const AdmissionService> service) : students(std::move(students)), service(std::move(service))
{
    if (!this->service)
    {
        throw std::invalid_argument("admission service cannot be null.");
    }
}

int StudentSystem::findByFN(const std::string &fn) const
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getFN() == fn)
        {
            return i;
        }
    }
    return -1;
}

void StudentSystem::addStudent(const Student &student)
{
    if (findByFN(student.getFN()) != -1)
    {
        throw std::runtime_error("student already exists");
    }
    students.push_back(student);
}

void StudentSystem::removeStudent(const std::string &fn)
{
    if (findByFN(fn) == -1)
    {
        throw std::runtime_error("student doesn't exist");
    }
    std::erase_if(students, [&fn](const Student &s)
                  { return fn == s.getFN(); });
}

std::optional<Student> StudentSystem::operator[](const std::string &fn) const
{
    if (findByFN(fn) == -1)
    {
        return std::nullopt;
    }
    return students[findByFN(fn)];
}

AdmissionResult StudentSystem::check(const Student &student) const
{
    return service->check(student);
}

std::vector<Student> StudentSystem::filter(std::function<bool(const Student &)> predicate) const
{
    std::vector<Student> result;
    for (const auto &s : students)
    {
        if (predicate(s))
        {
            result.push_back(s);
        }
    }
    return result;
}

std::vector<Student> StudentSystem::sorted(std::function<bool(const Student &, const Student &)> comparator) const
{
    std::vector<Student> result = students;
    std::sort(result.begin(), result.end(), comparator);
    return result;
}

void StudentSystem::forEach(std::function<void(const Student &)> action) const
{
    for (const auto &s : students)
    {
        action(s);
    }
}
