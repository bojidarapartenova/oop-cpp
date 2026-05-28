#pragma once

#include "AdmissionRequirement.h"

class MinPassedByCatReq : public AdmissionRequirement
{
private:
    int minCount;
    Category category;

public:
    MinPassedByCatReq(int minCount, Category categoty);

    std::string check(const Student &student) const override;
    AdmissionRequirement *clone() const override;
};