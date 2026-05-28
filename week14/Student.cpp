#include "Student.h"

#include <iostream>

Student::Student(const std::string &fn, const std::string &name, std::vector<Course> passedCourses, double avgGrade) : facultyNumber(fn), name(name), passedCourses(std::move(passedCourses)), avgGrade(avgGrade)
{
    if (fn.empty())
    {
        throw std::invalid_argument("faculty number can't be empty");
    }

    if (name.empty())
    {
        throw std::invalid_argument("name can't be empty");
    }

    if (avgGrade < 2.00 || avgGrade > 6.00)
    {
        throw std::invalid_argument("grade must be between 2.00 and 6.00");
    }

    for (const auto &c : passedCourses)
    {
        credits += c.getCredits();
    }
}

std::string Student::getFN() const
{
    return facultyNumber;
}

std::string Student::getName() const
{
    return name;
}

std::vector<Course> Student::getPassedCourses() const
{
    return passedCourses;
}

int Student::getCredits() const
{
    return credits;
}

double Student::getAvgGrade() const
{
    return avgGrade;
}
