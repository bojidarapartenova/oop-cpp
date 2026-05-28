#include "AdmissionResult.h"
#include <iostream>

AdmissionResult::AdmissionResult(bool isAdmitted, std::vector<std::string> reasons) : isAdmitted(isAdmitted), reasons(std::move(reasons)) {}

bool AdmissionResult::getIsAdmitted() const
{
    return isAdmitted;
}

std::vector<std::string> AdmissionResult::getReasons() const
{
    return reasons;
}

void AdmissionResult::print() const
{
    if (isAdmitted)
    {
        std::cout << "Student is admitted to the state exam." << std::endl;
    }
    else
    {
        std::cout << "Student is not admitted to the state exam:" << std::endl;
        for (const auto &r : reasons)
        {
            std::cout << "- " << r << std::endl;
        }
    }
}
