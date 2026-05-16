#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name, int age, double weight, bool isIndoor) : Animal(name, "Cat", age, weight), isIndoor(isIndoor), livesLeft(9), scratchCount(0) {}

bool Cat::getIsIndoor() const
{
    return isIndoor;
}

int Cat::getLivesLeft() const
{
    return livesLeft;
}

int Cat::getScratchCount() const
{
    return scratchCount;
}

void Cat::loseLife()
{
    livesLeft--;
    if (livesLeft < 0)
    {
        livesLeft = 0;
    }
}

void Cat::scratch()
{
    scratchCount++;
    if (scratchCount >= 5)
    {
        loseLife();
        scratchCount = 0;
    }
}

bool Cat::isAlive() const
{
    return livesLeft > 0;
}

void Cat::displayInfo() const
{
    Animal::displayInfo();
    std::cout << isIndoor << " " << livesLeft << " " << scratchCount << std::endl;
}
