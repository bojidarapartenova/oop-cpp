#include "MinCreditsReq.h"

MinCreditsReq::MinCreditsReq(int minCredits) : minCredits(minCredits)
{
    if (minCredits <= 0)
    {
        throw std::invalid_argument("credits must be a positive number");
    }
}

std::string MinCreditsReq::check(const Student &student) const
{
    if (minCredits > student.getCredits())
    {
        return "Student does not have enough credits";
    }
    return "";
}

AdmissionRequirement *MinCreditsReq::clone() const
{
    return new MinCreditsReq(*this);
}
