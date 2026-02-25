#include <iostream>
#include <string>
#include <fstream>
const int HERB_HEAL = 30;

class AgentInventory
{
private:
    std::string agentName;
    int healthLevel;
    int handgunAmmo;
    int greenHerbs;

public:
    void setAgentName(std::string agentName_)
    {
        agentName = agentName_;
    }

    void setHealthLevel(int healthLevel_)
    {
        if (healthLevel_ < 0)
        {
            healthLevel = 0;
        }
        else if (healthLevel_ > 100)
        {
            healthLevel = 100;
        }
        else
        {
            healthLevel = healthLevel_;
        }
    }

    void setHandgunAmmo(int handgunAmmo_)
    {
        if (handgunAmmo_ < 0)
        {
            handgunAmmo = 0;
        }
        else
        {
            handgunAmmo = handgunAmmo_;
        }
    }

    void setGreenHerbs(int greenHerbs_)
    {
        if (greenHerbs_ < 0)
        {
            greenHerbs = 0;
        }
        else
        {
            greenHerbs = greenHerbs_;
        }
    }

    void takeDamage(int damage)
    {
        healthLevel -= damage;

        if (healthLevel <= 0)
        {
            healthLevel = 0;
            std::cout << "YOU ARE DEAD" << std::endl;
        }
    }

    void useHerb()
    {
        if (greenHerbs > 0)
        {
            greenHerbs--;
            healthLevel += HERB_HEAL;
            if (healthLevel > 100)
            {
                healthLevel = 100;
            }
            std::cout << "Herb used. Health: " << healthLevel << " Herbs left: " << greenHerbs << std::endl;
        }
        else
        {
            std::cout << "No herbs left!" << std::endl;
        }
    }

    void shoot()
    {
        if (handgunAmmo > 0)
        {
            handgunAmmo--;
            std::cout << "Ammo used. Ammo left: " << handgunAmmo << std::endl;
        }
        else
        {
            std::cout << "No ammo left!" << std::endl;
        }
    }

    void loot(int ammo, int herbs)
    {
        handgunAmmo += ammo;
        greenHerbs += herbs;
        std::cout << "Looted " << ammo << " ammo and " << herbs << " herbs." << std::endl;
    }

    void saveProgress(const std::string &filename)
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cout << "Cannot open file!" << std::endl;
            return;
        }

        file << agentName << "\n";
        file << healthLevel << "\n";
        file << handgunAmmo << "\n";
        file << greenHerbs << "\n";
        file.close();
    }

    void loadProgress(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cout << "Cannot open file!" << std::endl;
            return;
        }

        std::string line;

        std::getline(file, agentName);
        std::getline(file, line);
        healthLevel = std::stoi(line);
        std::getline(file, line);
        handgunAmmo = std::stoi(line);
        std::getline(file, line);
        greenHerbs = std::stoi(line);

        std::cout << "Loaded progress for " << agentName << ":\n";
        std::cout << "Health: " << healthLevel
                  << ", Ammo: " << handgunAmmo
                  << ", Herbs: " << greenHerbs << std::endl;
    }
};

int main()
{
    AgentInventory agent;

    std::string name;
    int health, ammo, herbs;

    std::cout << "Enter agent name: ";
    std::cin >> name;
    std::cout << "Enter health: ";
    std::cin >> health;
    std::cout << "Enter ammo: ";
    std::cin >> ammo;
    std::cout << "Enter herbs: ";
    std::cin >> herbs;

    agent.setAgentName(name);
    agent.setHealthLevel(health);
    agent.setHandgunAmmo(ammo);
    agent.setGreenHerbs(herbs);

    std::cout << "damage: ";
    int damage;
    std::cin >> damage;
    agent.takeDamage(damage);

    agent.shoot();
    agent.useHerb();

    std::cout << "ammo: ";
    int newAmmo;
    std::cin >> newAmmo;
    std::cout << "herb: ";
    int newHerbs;
    std::cin >> newHerbs;
    agent.loot(newAmmo, newHerbs);

    std::cout << "Enter file name to save: ";
    std::string saveFile;
    std::cin >> saveFile;
    agent.saveProgress(saveFile);

    AgentInventory loadedAgent;
    loadedAgent.loadProgress(saveFile);
}