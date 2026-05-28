#pragma once

#include <string>
#include <vector>
#include "Course.h"

class Student
{
private:
    std::string facultyNumber;
    std::string name;
    std::vector<Course> passedCourses;
    int credits;
    double avgGrade;

public:
    Student(const std::string &fn, const std::string &name, std::vector<Course> passedCourses, double avgGrade);

    std::string getFN() const;
    std::string getName() const;
    std::vector<Course> getPassedCourses() const;
    int getCredits() const;
    double getAvgGrade() const;
};