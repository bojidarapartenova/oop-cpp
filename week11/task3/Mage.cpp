#include "Mage.h"

Mage::Mage(std::string name, int health, int attackPower, int defense, int mana, int spellPower) : Character(name, health, attackPower, defense), mana(mana), maxMana(mana), spellPower(spellPower), spellsCast(0) {}

int Mage::getMana() const
{
    return mana;
}

int Mage::getMaxMana() const
{
    return maxMana;
}

int Mage::getSpellPower() const
{
    return spellPower;
}

int Mage::getSpellsCast() const
{
    return spellsCast;
}

void Mage::restoreMana(int amount)
{
    mana += amount;
    if (mana > maxMana)
    {
        mana = maxMana;
    }
}

bool Mage::castFireball(Character &target)
{
    if (mana < 30)
    {
        return false;
    }

    mana -= 30;
    target.takeDamage(spellPower * 2);
    spellsCast += 1;
    return true;
}

bool Mage::castHeal(Character &target)
{
    if (mana < 20)
    {
        return false;
    }

    mana -= 20;
    target.heal(spellPower);
    spellsCast++;
    return true;
}

bool Mage::castFrostbolt(Character &target)
{
    if (mana < 15)
    {
        return false;
    }

    mana -= 15;
    target.takeDamage(spellPower);
    target.reduceAttackPower(5);
    spellsCast++;
    return true;
}

void Mage::onLevelUp()
{
    Character::onLevelUp();
    maxMana += 20;
    mana = maxMana;
    spellPower += 5;
}

void Mage::displayInfo() const
{
    Character::displayInfo();
}
