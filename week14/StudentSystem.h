#pragma once

#include "Student.h"
#include "AdmissionService.h"
#include <memory>
#include <functional>
#include <optional>

class StudentSystem
{
private:
    std::vector<Student> students;
    std::shared_ptr<const AdmissionService> service;

public:
    StudentSystem(std::vector<Student> students, std::shared_ptr<const AdmissionService> service);

    int findByFN(const std::string &fn) const;
    void addStudent(const Student &student);

    void removeStudent(const std::string &fn);

    std::optional<Student> operator[](const std::string &fn) const;

    AdmissionResult check(const Student &student) const;

    std::vector<Student> filter(std::function<bool(const Student &)> predicate) const;
    std::vector<Student> sorted(std::function<bool(const Student &, const Student &)> comparator) const;
    void forEach(std::function<void(const Student &)> action) const;

    template <typename T>
    std::vector<T> map(std::function<T(const Student &)> transform) const
    {
        std::vector<T> result;
        result.reserve(students.size());
        for (const auto &s : students)
        {
            result.push_back(transform(s));
        }
        return result;
    }
};