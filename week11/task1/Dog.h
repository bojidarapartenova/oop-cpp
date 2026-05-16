#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal
{
private:
    std::string breed;
    bool isTrained;
    int tricksKnown;

public:
    Dog(std::string name, int age, double weight, std::string breed, bool isTrained);

    const std::string &getBreed() const;
    bool getIsTrained() const;
    int getTricksKnown() const;
    void learnTrick();
    void train();
    void displayInfo() const;
    bool canCompete() const;
};

#endif