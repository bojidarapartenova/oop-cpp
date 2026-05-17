#ifndef CAT_H
#define CAT_h

#include "Animal.h"

class Cat : public Animal
{
private:
    bool isIndoor;
    int livesLeft;
    int scratchCount;

public:
    Cat(std::string name, int age, double weight, bool isIndoor);

    bool getIsIndoor() const;
    int getLivesLeft() const;
    int getScratchCount() const;
    void loseLife();
    void scratch();
    bool isAlive() const;
    void displayInfo() const override;
};

#endif