#pragma once

#include "AdmissionRequirement.h"

class PassedByNameReq : public AdmissionRequirement
{
private:
    std::vector<std::string> coursesNames;

public:
    PassedByNameReq(std::vector<std::string> coursesNames);

    std::string check(const Student &student) const override;
    AdmissionRequirement *clone() const override;
};