#include <iostream>
#include "soldier.h"

Soldier::Soldier(int healthPoints_, Rank rank_, int love_, int bulletsLeft_) : healthPoints(healthPoints_), rank(rank_), love(love_), bulletsLeft(bulletsLeft_)
{
}

void Soldier::shootAt(Soldier &soldier)
{
    if (bulletsLeft > 0)
    {
        double chance = 0;
        if (this->rank == Rank::Private)
        {
            chance = 0.6;
        }
        else if (this->rank == Rank::Corporal)
        {
            chance = 0.7;
        }
        else if (this->rank == Rank::Sergeant)
        {
            chance = 0.8;
        }
        else if (this->rank == Rank::Major)
        {
            chance = 0.9;
        }

        double r = (double)std::rand() / RAND_MAX;
        if (r <= chance)
        {
            soldier.getShot();
            love++;
            std::cout << "You hit." << std::endl;
        }
        else
        {
            std::cout << "You failed." << std::endl;
        }
        bulletsLeft--;

        if (bulletsLeft < 0)
        {
            bulletsLeft = 0;
        }
    }
    else
    {
        std::cout << "Not enough bullets." << std::endl;
    }
}

void Soldier::getShot()
{
    healthPoints--;
    if (healthPoints < 0)
    {
        healthPoints = 0;
    }
    std::cout << "You got shot." << std::endl;
}

int Soldier::getHealthPoints()
{
    return this->healthPoints;
}

void Soldier::increaseRank(Soldier &soldier)
{
    if (this->rank > soldier.rank)
    {
        if (soldier.rank == Rank::Private)
        {
            soldier.rank == Rank::Corporal;
        }
        else if (soldier.rank == Rank::Corporal)
        {
            soldier.rank == Rank::Sergeant;
        }
        else if (soldier.rank == Rank::Sergeant)
        {
            soldier.rank == Rank::Major;
        }
        soldier.getIncreased();
        std::cout << "You increased soldiers rank." << std::endl;
    }
    else
    {
        std::cout << "You can't increase soldiers rank." << std::endl;
    }
}

void Soldier::getIncreased()
{
    std::cout << "You got increased" << std::endl;
}

int main()
{
}