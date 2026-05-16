#include <string>

class Vehicle
{
private:
    std::string brand;
    std::string model;
    int year;
    double mileage;

public:
    Vehicle(const std::string &brand_, const std::string &model_, int year_, double mileage_);

    int getYear() const;
    double getMileage() const;
    const std::string &getBrand() const;

    auto operator<=>(const Vehicle &other) const
    {
        if (auto cmp = year <=> other.year; cmp != 0)
        {
            return cmp;
        }
        return std::compare_strong_order_fallback(mileage, other.mileage);
    }

    friend std::ostream &operator<<(std::ostream &, const Vehicle &);
};