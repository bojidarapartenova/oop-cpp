#include "Animal.h"
#include <iostream>

Animal::Animal(std::string name, std::string species, int age, double weight) : name(name), species(species), age(age), weight(weight) {}

const std::string &Animal::getName() const
{
    return name;
}

const std::string &Animal::getSpecies() const
{
    return species;
}

int Animal::getAge() const
{
    return age;
}

double Animal::getWeight() const
{
    return weight;
}

void Animal::displayInfo() const
{
    std::cout << name << " " << species << " " << age << " " << weight << std::endl;
}

bool Animal::operator==(const Animal &other) const
{
    return (name == other.name && species == other.species && age == other.age && weight == other.weight);
}

std::ostream &operator<<(std::ostream &os, const Animal &a)
{
    os << a.name << " " << a.species << " " << a.age << " " << a.weight << "\n";
    return os;
}
