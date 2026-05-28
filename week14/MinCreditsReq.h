#pragma once

#include "AdmissionRequirement.h"

class MinCreditsReq : public AdmissionRequirement
{
private:
    int minCredits;

public:
    MinCreditsReq(int minCredits);

    std::string check(const Student &student) const override;
    AdmissionRequirement *clone() const override;
};