#include "army.h"
#include <iostream>
#include <utility>

void Army::resize(int newCapacity)
{
    Soldier *newArmy = new Soldier[newCapacity];

    if (newCapacity < size)
        size = newCapacity;

    for (size_t i = 0; i < size; i++)
    {
        newArmy[i] = army[i];
    }

    delete[] army;
    army = newArmy;
    capacity = newCapacity;
}

Army::Army(int size) : capacity(size), size(0), army(new Soldier[size]) {}

Army::Army(int size, const Soldier &example) : capacity(size), size(0), army(new Soldier[size])
{
    for (size_t i = 0; i < size; i++)
    {
        army[i] = example;
    }
}

Army::Army(const Army &other) : size(other.size), capacity(other.capacity), army(new Soldier[other.capacity])
{
    for (size_t i = 0; i < size; i++)
    {
        army[i] = other.army[i];
    }
}

Army::Army(Army &&other) noexcept : size(std::move(other.size)), capacity(std::move(other.capacity)), army(std::move(other.army))
{
    other.size = 0;
    other.capacity = 0;
    other.army = nullptr;
}

Army &Army::operator=(Army &&other) noexcept
{
    if (this != &other)
    {
        delete[] army;

        size = std::move(other.size);
        capacity = std::move(other.capacity);
        army = std::move(other.army);

        size = 0;
        capacity = 0;
        army = nullptr;
    }
}

Army::~Army()
{
    delete[] army;
    army = nullptr;
}

Army &Army::operator=(const Army &other)
{
    if (this != &other)
    {
        delete[] army;

        size = other.size;
        capacity = other.capacity;

        army = new Soldier[capacity];
        for (size_t i = 0; i < size; i++)
        {
            army[i] = other.army[i];
        }
    }

    return *this;
}

int Army::getSize() const
{
    return size;
}

Soldier &Army::getSoldier(int soldierId)
{
    if (soldierId < 0 || soldierId >= size)
    {
        throw 1;
    }

    return army[soldierId];
}

const Soldier &Army::getSoldier(int soldierId) const
{
    if (soldierId < 0 || soldierId >= size)
    {
        throw 1;
    }

    return army[soldierId];
}

void Army::addSoldier(const Soldier &soldier)
{
    if (size >= capacity)
    {
        resize(size * 2);
    }

    army[size] = soldier;
    size++;
}

void Army::removeSoldier(int soldierId)
{
    if (soldierId >= size || soldierId < 0)
    {
        throw 2;
    }

    for (size_t i = soldierId + 1; i < size; i++)
    {
        army[i - 1] = army[i];
    }

    size--;
}