#include "AdmissionService.h"

AdmissionService::AdmissionService(const AdmissionService &other)
{
    for (const auto &r : other.requirements)
    {
        if (r)
        {
            this->requirements.push_back(std::unique_ptr<AdmissionRequirement>(r->clone()));
        }
    }
}

AdmissionService &AdmissionService::operator=(const AdmissionService &other)
{
    if (this != &other)
    {
        requirements.clear();
        for (const auto &r : other.requirements)
        {
            if (r)
            {
                this->requirements.push_back(std::unique_ptr<AdmissionRequirement>(r->clone()));
            }
        }
    }
    return *this;
}

void AdmissionService::addRequirement(const AdmissionRequirement &requirement)
{
    requirements.push_back(std::unique_ptr<AdmissionRequirement>(requirement.clone()));
}

AdmissionResult AdmissionService::check(const Student &student) const
{
    std::vector<std::string> reasons;

    for (const auto &r : requirements)
    {
        if (r)
        {
            std::string error = r->check(student);

            if (!error.empty())
            {
                reasons.push_back(error);
            }
        }
    }

    bool isAdmitted = reasons.empty();
    return AdmissionResult(isAdmitted, reasons);
}
