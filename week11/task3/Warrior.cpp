#include "Warrior.h"

Warrior::Warrior(std::string name, int health, int attackPower, int defense) : Character(name, health, attackPower, defense), rage(0), maxRage(100), berserkActive(false) {}

int Warrior::getRage() const
{
    return rage;
}

bool Warrior::isBerserk() const
{
    return isBerserk;
}

void Warrior::takeDamage(int amount)
{
    Character::takeDamage(amount);
    rage += 10;
}

void Warrior::activateBerserk()
{
    if (rage >= 50)
    {
        berserkActive = true;
        attackPower *= 2;
        rage = 0;
    }
}

void Warrior::deactivateBerserk()
{
    attackPower /= 2;
    berserkActive = false;
}

void Warrior::strike(Character &target)
{
    target.takeDamage(1);
    if (berserkActive)
    {
        target.takeDamage(15);
    }
}

void Warrior::onLevelUp()
{
    Character::onLevelUp();
    maxRage += 20;
    defense += 2;
}

void Warrior::displayInfo() const
{
    Character::displayInfo();
}
