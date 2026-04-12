#include "Car.h"
#include <cstddef>
class Parking
{
private:
    Car *cars;
    size_t count;
    size_t capacity;

public:
    Parking(size_t cap = 10);
    Parking(const Parking &other);
    Parking &operator=(const Parking &other);
    ~Parking();

    void addCar(const Car &car);
    Car &getCar(size_t idx);
    const Car &getCar(size_t idx) const;
    void removeCar(size_t idx);
    size_t getCount() const;
    size_t getCapacity() const;
};