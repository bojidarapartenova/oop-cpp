#include "Vehicle.h"
#include <vector>
#include <optional>

class Garage
{
private:
    std::vector<Vehicle> vehicles;

public:
    void addVehicle(const Vehicle &v);
    void removeOld(int yearThreshold);
    std::vector<Vehicle> filterByMileage(double maxMileage) const;
    std::vector<Vehicle> filterByBrand(const std::string &brand) const;
    void sortByYear();
    double averageMileage() const;
    std::optional<Vehicle> newestVehicle() const;
    void print() const;
};