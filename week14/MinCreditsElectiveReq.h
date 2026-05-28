#pragma once

#include "AdmissionRequirement.h"

class MinCreditsElectiveReq : public AdmissionRequirement
{
private:
    int minCredits;

public:
    MinCreditsElectiveReq(int minCredits);

    std::string check(const Student &student) const override;
    AdmissionRequirement *clone() const override;
};