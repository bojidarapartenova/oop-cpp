#pragma once

#include "AdmissionRequirement.h"

class PassedAllMandatoryReq : public AdmissionRequirement
{
private:
    std::vector<std::string> mandatoryCourses;

public:
    PassedAllMandatoryReq(std::vector<std::string> mandatoryCourses);

    std::string check(const Student &student) const override;
    AdmissionRequirement *clone() const override;
};