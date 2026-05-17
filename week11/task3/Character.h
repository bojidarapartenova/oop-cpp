#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int defense;
    int level;
    int experience;

public:
    Character(std::string name, int health, int attackPower, int defense);
    virtual ~Character() = default;

    const std::string &getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttackPower() const;
    int getDefense() const;
    int getLevel() const;
    int getExperience() const;
    bool isAlive() const;
    void takeDamage(int amount);
    void heal(int amount);
    void gainExperience(int amount);
    void displayInfo() const;

    void reduceAttackPower(int amount);

    bool operator==(const Character &other) const;

    auto operator<=>(const Character &other) const
    {
        if (auto cmp = level <=> other.level; cmp != 0)
        {
            return health <=> other.health;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Character &c);

protected:
    void levelUp();
    virtual void onLevelUp();
};

#endif