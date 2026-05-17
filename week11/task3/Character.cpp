#include "Character.h"
#include <iostream>

Character::Character(std::string name, int health, int attackPower, int defense) : name(name), health(health), maxHealth(health), attackPower(attackPower), defense(defense), level(1), experience(0) {}

const std::string &Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return health;
}

int Character::getMaxHealth() const
{
    return maxHealth;
}

int Character::getAttackPower() const
{
    return attackPower;
}

int Character::getDefense() const
{
    return defense;
}

int Character::getLevel() const
{
    return level;
}

int Character::getExperience() const
{
    return experience;
}

bool Character::isAlive() const
{
    return health > 0;
}

void Character::takeDamage(int amount)
{
    health -= std::max(0, amount - defense);
    if (health < 0)
    {
        health = 0;
    }
}

void Character::heal(int amount)
{
    health += amount;
    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Character::gainExperience(int amount)
{
    experience += amount;
    if (experience >= level * 100)
    {
        levelUp();
    }
}

void Character::displayInfo() const
{
    std::cout << name << " " << health << " " << level << " " << attackPower << " " << experience << "\n";
}

void Character::reduceAttackPower(int amount)
{
    attackPower -= amount;
}

void Character::levelUp()
{
    level++;
    experience = 0;
    onLevelUp();
}

void Character::onLevelUp()
{
    maxHealth += 10;
    health = maxHealth;
}

bool Character::operator==(const Character &other) const
{
    return name == other.name;
}

std::ostream &operator<<(std::ostream &os, const Character &c)
{
    os << c.name;
    return os;
}
