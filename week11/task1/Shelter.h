#ifndef SHELTER_H
#define SHELTER_H

#include "Dog.h"
#include "Cat.h"
#include <vector>
#include <optional>

class Shelter
{
private:
    std::string shelterName;
    std::vector<Dog> dogs;
    std::vector<Cat> cats;

public:
    Shelter(std::string shelterName);

    void addDog(const Dog &d);
    void addCat(const Cat &c);
    void removeDogByName(const std::string &name);
    void removeCatByName(const std::string &name);
    void listDogs() const;
    void listCats() const;
    std::vector<Dog> getCompetitiveDogs() const;
    std::optional<Dog> findOldestDog() const;
    std::optional<Cat> findCatWithMostLives() const;
    int totalAnimals() const;

    explicit operator bool() const;
};

#endif