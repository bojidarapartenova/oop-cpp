#include "PassedByNameReq.h"

PassedByNameReq::PassedByNameReq(std::vector<std::string> coursesNames) : coursesNames(coursesNames)
{
    if (coursesNames.empty())
    {
        throw std::invalid_argument("courses can't be empty");
    }
}

std::string PassedByNameReq::check(const Student &student) const
{
    for (const auto &name : coursesNames)
    {
        bool passed = std::any_of(student.getPassedCourses().begin(), student.getPassedCourses().end(), [&name](const Course &course)
                                  { return name == course.getName(); });

        if (!passed)
        {
            return "Student hasn't passed all";
        }
    }
    return "";
}

AdmissionRequirement *PassedByNameReq::clone() const
{
    return new PassedByNameReq(*this);
}
