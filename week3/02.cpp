#include <iostream>
#include <string>

class Character
{
private:
    std::string name;
    int level = 1;
    int health = 100;
    int mana = 50;
    int strength = 10;
    int agility = 10;

    Character(const std::string name_, int level_, int health_, int mana_, int strength_, int agility_) : name(name_), level(level_), health(health_), mana(mana_), strength(strength_), agility(agility_) {}

public:
    class Builder
    {
    private:
        std::string name_;
        int level_ = 1;
        int health_ = 100;
        int mana_ = 50;
        int strength_ = 10;
        int agility_ = 10;

    public:
        Builder(const std::string name) : name_(name) {}

        Builder &setLevel(int level)
        {
            level_ = level;
            return *this;
        }

        Builder &setHealth(int health)
        {
            health_ = health;
            return *this;
        }

        Builder &setMana(int mana)
        {
            mana_ = mana;
            return *this;
        }

        Builder &setStrength(int strength)
        {
            strength_ = strength;
            return *this;
        }

        Builder &setAgility(int agility)
        {
            agility_ = agility;
            return *this;
        }

        Character build()
        {
            return Character(name_, level_, health_, mana_, strength_, agility_);
        }
    };

public:
    void printInfo()
    {
        std::cout << "Name: " << name << ", level: " << level << ", health: " << health << ", mana: " << mana << ", strength: " << strength << ", agility: " << agility;
    }
};

int main()
{
    Character character = Character::Builder("Leon")
                              .setLevel(120)
                              .setMana(100)
                              .build();

    character.printInfo();
}