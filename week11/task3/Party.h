#ifndef PARTY_H
#define PARTY_H

#include <string>
#include <vector>
#include <optional>
#include "Warrior.h"
#include "Mage.h"

class Party
{
private:
    std::string partyName;
    std::vector<Warrior> warriors;
    std::vector<Mage> mages;

public:
    Party(std::string partyName);

    void addWarrior(const Warrior &w);
    void addMage(const Mage &m);
    void removeByName(const std::string &name);
    void listAll() const;
    bool isWiped() const;
    void restoreAll(int amount);
    std::optional<Warrior> findStrongestWarrior() const;
    std::optional<Mage> findMostExperienced() const;
    int totalLevel() const;

    explicit operator bool() const;
};

#endif