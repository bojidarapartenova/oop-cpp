#pragma once
#include <string>
class Car
{
private:
    std::string brand;
    std::string model;
    int year;

public:
    Car() = default;
    Car(const std::string &brand, const std::string &model, int year);
};