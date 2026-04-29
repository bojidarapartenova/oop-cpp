#include "Warrior.h"

Warrior::Warrior(std::string name, int health, int attackPower, int defense) : Character(name, health, attackPower, defense) {}

int Warrior::getRage() const
{
    return rage;
}

bool Warrior::isBerserk() const
{
    return berserkActive;
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
        Character::setAttackPower(getAttackPower() * 2);
    }
}

void Warrior::deactivateBerserk()
{
    Character::setAttackPower(getAttackPower() / 2);
    berserkActive = false;
}

void Warrior::strike(Character &target)
{
    target.takeDamage(1);
    if (isBerserk())
    {
        target.takeDamage(15);
    }
}

void Warrior::onLevelUp()
{
    Character::onLevelUp();
    rage += 20;
}
