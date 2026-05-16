#include "Shelter.h"

Shelter::Shelter(std::string shelterName) : shelterName(shelterName) {}

void Shelter::addDog(const Dog &d)
{
    dogs.push_back(d);
}

void Shelter::addCat(const Cat &c)
{
    cats.push_back(c);
}

void Shelter::removeDogByName(const std::string &name)
{
    std::erase_if(dogs, [&name](const Dog &d)
                  { return d.getName() == name; });
}

void Shelter::removeCatByName(const std::string &name)
{
    std::erase_if(cats, [&name](const Cat &c)
                  { return c.getName() == name; });
}

void Shelter::listDogs() const
{
    for (Dog d : dogs)
    {
        d.displayInfo();
    }
}

void Shelter::listCats() const
{
    for (Cat c : cats)
    {
        c.displayInfo();
    }
}

std::vector<Dog> Shelter::getCompetitiveDogs() const
{
    std::vector<Dog> result;
    for (Dog d : dogs)
    {
        if (d.canCompete())
        {
            result.push_back(d);
        }
    }
    return result;
}

std::optional<Dog> Shelter::findOldestDog() const
{
    if (dogs.empty())
    {
        return std::nullopt;
    }

    const Dog *oldest = &dogs[0];
    for (const auto &d : dogs)
    {
        if (d.getAge() > oldest->getAge())
        {
            oldest = &d;
        }
    }
    return *oldest;
}

std::optional<Cat> Shelter::findCatWithMostLives() const
{
    if (cats.empty())
    {
        return std::nullopt;
    }

    const Cat *maxLives = &cats[0];
    for (const auto &c : cats)
    {
        if (c.getLivesLeft() > maxLives->getLivesLeft())
        {
            maxLives = &c;
        }
    }
    return *maxLives;
}

int Shelter::totalAnimals() const
{
    return dogs.size() + cats.size();
}

Shelter::operator bool() const
{
    return (totalAnimals() > 0);
}
