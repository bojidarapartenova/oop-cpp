#include "MinPassedByCatReq.h"

MinPassedByCatReq::MinPassedByCatReq(int minCount, Category categoty) : minCount(minCount), category(category)
{
    if (minCount <= 0)
    {
        throw std::invalid_argument("count must be a positive number");
    }
}

std::string MinPassedByCatReq::check(const Student &student) const
{
    int count = 0;
    for (const auto &c : student.getPassedCourses())
    {
        if (c.getCategory() == category)
        {
            count++;
        }
    }

    if (count < minCount)
    {
        return "Student hasn't passed enough courses of this category";
    }
    return "";
}

AdmissionRequirement *MinPassedByCatReq::clone() const
{
    return new MinPassedByCatReq(*this);
}
