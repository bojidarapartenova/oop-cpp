#include "MinAvgGradeReq.h"

MinAvgGradeReq::MinAvgGradeReq(double minAvgGrade) : minAvgGrade(minAvgGrade)
{
    if (minAvgGrade < 2.00 || minAvgGrade > 6.00)
    {
        throw std::invalid_argument("grade must be between 2.00 and 6.00");
    }
}

std::string MinAvgGradeReq::check(const Student &student) const
{
    if (student.getAvgGrade() < minAvgGrade)
    {
        return "student's average grade isn't enough";
    }
    return "";
}

AdmissionRequirement *MinAvgGradeReq::clone() const
{
    return new MinAvgGradeReq(*this);
}
