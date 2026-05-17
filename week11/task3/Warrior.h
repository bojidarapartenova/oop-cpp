#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character
{
private:
    int rage;
    int maxRage;
    bool berserkActive;

public:
    Warrior(std::string name, int health, int attackPower, int defense);

    int getRage() const;
    bool isBerserk() const;
    void takeDamage(int amount);
    void activateBerserk();
    void deactivateBerserk();
    void strike(Character &target);
    void onLevelUp();
    void displayInfo() const;
};

#endif