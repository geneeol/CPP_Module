#pragma once

#include <string>

class ClapTrap
{
  private:
    ClapTrap();

  protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

  public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &clapTrap);
    ClapTrap &operator=(const ClapTrap &clapTrap);
    virtual ~ClapTrap();
    ClapTrap(const std::string &name, unsigned int hitPoints,
             unsigned int energyPoints, unsigned int attackDamage);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    const std::string &getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};