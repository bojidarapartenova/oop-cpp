#include "Garage.h"
#include <algorithm>
#include <print>

void Garage::addVehicle(const Vehicle &v)
{
    vehicles.push_back(v);
}

void Garage::removeOld(int yearThreshold)
{
    std::erase_if(vehicles, [&](const Vehicle &v)
                  { return v.getYear() < yearThreshold; });
}

std::vector<Vehicle> Garage::filterByMileage(double maxMileage) const
{
    std::vector<Vehicle> result;
    for (const auto &v : vehicles)
    {
        if (v.getMileage() <= maxMileage)
        {
            result.push_back(v);
        }
    }
    return result;
}

std::vector<Vehicle> Garage::filterByBrand(const std::string &brand) const
{
    std::vector<Vehicle> result;
    for (const auto &v : vehicles)
    {
        if (v.getBrand() == brand)
        {
            result.push_back(v);
        }
    }
    return result;
}

void Garage::sortByYear()
{
    std::sort(vehicles.begin(), vehicles.end(), [](const Vehicle &a, const Vehicle &b)
              { return a.getYear() < b.getYear(); });
}

double Garage::averageMileage() const
{
    if (vehicles.empty())
    {
        return 0.0;
    }

    double sum = 0;
    int count = vehicles.size();
    for (size_t i = 0; i < count; i++)
    {
        sum += vehicles[i].getMileage();
    }

    return sum / count;
}

std::optional<Vehicle> Garage::newestVehicle() const
{
    if (vehicles.empty())
    {
        return std::nullopt;
    }

    return *std::max_element(vehicles.begin(), vehicles.end(), [](const Vehicle &a, const Vehicle &b)
                             { return a.getYear() < b.getYear(); });
}

void Garage::print() const
{
    std::print("Vehicles:\n");
    for (const auto &v : vehicles)
    {
        std::print("Brand: {}, Year: {}, Mileage: {}\n", v.getBrand(), v.getYear(), v.getMileage());
    }
}
