#pragma once

#include <string>
#include "Student.h"

class AdmissionRequirement
{
public:
    virtual std::string check(const Student &student) const = 0;
    virtual AdmissionRequirement *clone() const = 0;

    virtual ~AdmissionRequirement() = default;
};