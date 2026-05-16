#include "Car.h"
#include "Parking.h"
#include <iostream>

Car::Car(const std::string &brand, const std::string &model, int year) : brand(brand), model(model), year(year) {}

Parking::Parking(size_t cap) : cars(new Car[cap]), count(0), capacity(cap) {}

Parking::Parking(const Parking &other) : cars(new Car[other.capacity]), count(other.count), capacity(other.capacity)
{
    for (size_t i = 0; i < count; i++)
    {
        cars[i] = other.cars[i];
    }
}

Parking &Parking::operator=(const Parking &other)
{
    if (this == &other)
    {
        return *this;
    }

    Car *newCars = new Car[other.capacity];
    for (size_t i = 0; i < count; i++)
    {
        newCars[i] = other.cars[i];
    }

    delete[] cars;

    cars = newCars;
    count = other.count;
    capacity = other.capacity;

    return *this;
}

Parking::~Parking()
{
    delete[] cars;
}

void Parking::addCar(const Car &car)
{
    if (count == capacity)
    {
        size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
        Car *newCars = new Car[newCapacity];
        for (size_t i = 0; i < count; i++)
        {
            newCars[i] = cars[i];
        }
        delete[] cars;
        cars = newCars;
        capacity = newCapacity;
    }
    cars[count] = car;
    count++;
}

Car &Parking::getCar(size_t idx)
{
    return cars[idx];
}

const Car &Parking::getCar(size_t idx) const
{
    return cars[idx];
}

void Parking::removeCar(size_t idx)
{
    for (size_t i = idx; i < count - 1; i++)
    {
        cars[i] = cars[i + 1];
    }
    count--;
}

size_t Parking::getCount() const
{
    return this->count;
}

size_t Parking::getCapacity() const
{
    return this->capacity;
}

int main()
{
}