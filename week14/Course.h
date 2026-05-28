#pragma once

#include <string>

enum class Category
{
    Programming,
    Mathematics,
    AppliedMathematics,
    Other
};

class Course
{
private:
    std::string name;
    int credits;
    Category category;
    bool isMandatory;

public:
    Course(const std::string &name, int credits, Category category, bool isMandatory);

    std::string getName() const;
    int getCredits() const;
    Category getCategory() const;
    bool getIsMandatory() const;
};
