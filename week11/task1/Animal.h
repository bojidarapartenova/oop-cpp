#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
private:
    std::string name;
    std::string species;
    int age;
    double weight;

public:
    Animal(std::string name, std::string species, int age, double weight);
    virtual ~Animal() = default;

    const std::string &getName() const;
    const std::string &getSpecies() const;
    int getAge() const;
    double getWeight() const;
    virtual void displayInfo() const;

    bool operator==(const Animal &other) const;

    auto operator<=>(const Animal &other) const
    {
        if (auto cmp = age <=> other.age; cmp != 0)
        {
            return cmp;
        }
        return name <=> other.name;
    }

    friend std::ostream &operator<<(std::ostream &os, const Animal &a);
};

#endif