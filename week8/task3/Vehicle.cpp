#include "Vehicle.h"
#include <fstream>

Vehicle::Vehicle(const std::string &brand_, const std::string &model_, int year_, double mileage_) : brand(brand_), model(model_), year(year_), mileage(mileage_) {}

int Vehicle::getYear() const
{
    return year;
}

double Vehicle::getMileage() const
{
    return mileage;
}

const std::string &Vehicle::getBrand() const
{
    return brand;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &v)
{
    os << "Brand: " << v.brand << " Model: " << v.model << " Year: " << v.year << " Mileage: " << v.mileage;

    return os;
}
