#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name, int age, double weight, std::string breed, bool isTrained) : Animal(name, "Dog", age, weight), breed(breed), isTrained(isTrained), tricksKnown(0) {}

const std::string &Dog::getBreed() const
{
    return breed;
}

bool Dog::getIsTrained() const
{
    return isTrained;
}

int Dog::getTricksKnown() const
{
    return tricksKnown;
}

void Dog::learnTrick()
{
    if (isTrained)
    {
        tricksKnown++;
    }
}

void Dog::train()
{
    isTrained = true;
}

void Dog::displayInfo() const
{
    Animal::displayInfo();
    std::cout << breed << " " << isTrained << " " << tricksKnown << std::endl;
}

bool Dog::canCompete() const
{
    return (isTrained && tricksKnown >= 3);
}
