#include "PassedAllMandatoryReq.h"

PassedAllMandatoryReq::PassedAllMandatoryReq(std::vector<std::string> mandatoryCourses) : mandatoryCourses(std::move(mandatoryCourses))
{
    if (mandatoryCourses.empty())
    {
        throw std::invalid_argument("mandatory courses can't be empty");
    }
}

std::string PassedAllMandatoryReq::check(const Student &student) const
{
    for (const auto &name : mandatoryCourses)
    {
        bool passed = std::any_of(student.getPassedCourses().begin(), student.getPassedCourses().end(), [&name](const Course &course)
                                  { return name == course.getName(); });

        if (!passed)
        {
            return "student hasn't passed all mandatory courses";
        }
    }
    return "";
}

AdmissionRequirement *PassedAllMandatoryReq::clone() const
{
    return new PassedAllMandatoryReq(*this);
}
