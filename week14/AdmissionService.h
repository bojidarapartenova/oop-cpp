#pragma once

#include "AdmissionRequirement.h"
#include "AdmissionResult.h"

class AdmissionService
{
private:
    std::vector<std::unique_ptr<AdmissionRequirement>> requirements;

public:
    AdmissionService() = default;

    AdmissionService(const AdmissionService &other);
    AdmissionService &operator=(const AdmissionService &other);

    AdmissionService(AdmissionService &&other) noexcept = default;
    AdmissionService &operator=(AdmissionService &&other) noexcept = default;
    ~AdmissionService() = default;

    void addRequirement(const AdmissionRequirement &requirement);

    AdmissionResult check(const Student &student) const;
};