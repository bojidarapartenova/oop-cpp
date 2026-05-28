#pragma once

#include "AdmissionRequirement.h"

class MinAvgGradeReq : public AdmissionRequirement
{
private:
    double minAvgGrade;

public:
    MinAvgGradeReq(double minAvgGrade);

    std::string check(const Student &student) const override;
    AdmissionRequirement *clone() const override;
};