#pragma once

#include <string>
#include <vector>

class AdmissionResult
{
private:
    bool isAdmitted;
    std::vector<std::string> reasons;

public:
    AdmissionResult(bool isAdmitted, std::vector<std::string> reasons);

    bool getIsAdmitted() const;
    std::vector<std::string> getReasons() const;

    void print() const;
};