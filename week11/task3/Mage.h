#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character
{
private:
    int mana;
    int maxMana;
    int spellPower;
    int spellsCast;

public:
    Mage(std::string name, int health, int attackPower, int defense, int mana, int spellPower);

    int getMana() const;
    int getMaxMana() const;
    int getSpellPower() const;
    int getSpellsCast() const;
    void restoreMana(int amount);
    bool castFireball(Character &target);
    bool castHeal(Character &target);
    bool castFrostbolt(Character &target);
    void onLevelUp();
    void displayInfo() const;
};

#endif