#include "Character.h"

class Warrior : public Character
{
private:
    int rage = 0;
    int maxRage = 100;
    bool berserkActive = false;

public:
    Warrior(std::string name, int health, int attackPower, int defense);

    int getRage() const;
    bool isBerserk() const;

    void takeDamage(int amount);
    void activateBerserk();
    void deactivateBerserk();
    void strike(Character &target);

    void onLevelUp() override;
};