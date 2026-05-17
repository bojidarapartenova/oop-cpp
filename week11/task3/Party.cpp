#include "Party.h"

Party::Party(std::string partyName) : partyName(partyName) {}

void Party::addWarrior(const Warrior &w)
{
    warriors.push_back(w);
}

void Party::addMage(const Mage &m)
{
    mages.push_back(m);
}

void Party::removeByName(const std::string &name)
{
    std::erase_if(warriors, [&name](const Warrior &w)
                  { return w.getName() == name; });

    std::erase_if(mages, [&name](const Mage &m)
                  { return m.getName() == name; });
}

void Party::listAll() const
{
    for (size_t i = 0; i < warriors.size(); i++)
    {
        warriors[i].displayInfo();
    }

    for (size_t i = 0; i < mages.size(); i++)
    {
        mages[i].displayInfo();
    }
}

bool Party::isWiped() const
{
    for (size_t i = 0; i < warriors.size(); i++)
    {
        if (warriors[i].isAlive())
        {
            return false;
        }
    }

    for (size_t i = 0; i < mages.size(); i++)
    {
        if (mages[i].isAlive())
        {
            return false;
        }
    }

    return true;
}

void Party::restoreAll(int amount)
{
    for (size_t i = 0; i < warriors.size(); i++)
    {
        if (warriors[i].isAlive())
        {
            warriors[i].heal(amount);
        }
    }

    for (size_t i = 0; i < mages.size(); i++)
    {
        if (mages[i].isAlive())
        {
            mages[i].heal(amount);
        }
    }
}

std::optional<Warrior> Party::findStrongestWarrior() const
{
    if (warriors.empty())
    {
        return std::nullopt;
    }

    const Warrior *strongest = &warriors[0];
    for (size_t i = 0; i < warriors.size(); i++)
    {
        if (warriors[i].getAttackPower() > strongest->getAttackPower())
        {
            strongest = &warriors[i];
        }
    }
    return *strongest;
}

std::optional<Mage> Party::findMostExperienced() const
{
    if (mages.empty())
    {
        return std::nullopt;
    }

    const Mage *mostExperienced = &mages[0];
    for (size_t i = 0; i < warriors.size(); i++)
    {
        if (mages[i].getLevel() > mostExperienced->getLevel())
        {
            if (mages[i].getExperience() > mostExperienced->getExperience())
            {
                mostExperienced = &mages[i];
            }
        }
    }
    return *mostExperienced;
}

int Party::totalLevel() const
{
    int result = 0;
    for (size_t i = 0; i < warriors.size(); i++)
    {
        result += warriors[i].getLevel();
    }

    for (size_t i = 0; i < mages.size(); i++)
    {
        result += mages[i].getLevel();
    }

    return result;
}

Party::operator bool() const
{
    return !isWiped() && (!warriors.empty() || !mages.empty());
}
