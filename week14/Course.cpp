#include "Course.h"

Course::Course(const std::string &name, int credits, Category category, bool isMandatory) : name(name), credits(credits), category(category), isMandatory(isMandatory)
{
    if (name.empty())
    {
        throw std::invalid_argument("name can't be empty");
    }

    if (credits <= 0)
    {
        throw std::invalid_argument("credits must be a positive number");
    }
}

std::string Course::getName() const
{
    return name;
}

int Course::getCredits() const
{
    return credits;
}

Category Course::getCategory() const
{
    return category;
}

bool Course::getIsMandatory() const
{
    return isMandatory;
}
