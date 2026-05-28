#include "MinCreditsElectiveReq.h"

MinCreditsElectiveReq::MinCreditsElectiveReq(int minCredits) : minCredits(minCredits)
{
    if (minCredits <= 0)
    {
        throw std::invalid_argument("credits must be a positive number");
    }
}

std::string MinCreditsElectiveReq::check(const Student &student) const
{
    int count = 0;
    for (const auto &c : student.getPassedCourses())
    {
        if (!c.getIsMandatory())
        {
            count += c.getCredits();
        }
    }

    if (count < minCredits)
    {
        return "Student doesn't have enough credits from elective courses";
    }
    return "";
}

AdmissionRequirement *MinCreditsElectiveReq::clone() const
{
    return new MinCreditsElectiveReq(*this);
}
