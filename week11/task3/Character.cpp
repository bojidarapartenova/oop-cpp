#include "Character.h"
#include <fstream>

Character::Character(std::string name, int health, int attackPower, int defense) : name(name), health(health), attackPower(attackPower), defense(defense) {}

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
    int damage = std::max(0, amount - defense);
    health = std::max(0, health - damage);
}

void Character::heal(int amount)
{
    health = std::min(maxHealth, health + amount);
}

void Character::gainExperience(int amount)
{
    experience += amount;
    if (experience >= level * 100)
    {
        levelUp();
    }
}

bool Character::operator==(const Character &other) const
{
    return name == other.name;
}

void Character::setAttackPower(int val)
{
    val = attackPower;
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

std::ostream &operator<<(std::ostream &os, const Character &c)
{
    os << c.name << ' ' << c.health << ' ' << c.experience;
    return os;
}
