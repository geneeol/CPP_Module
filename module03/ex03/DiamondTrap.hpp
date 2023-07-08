#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
    std::string name;
    DiamondTrap();

  public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI(void);
    void printInfo(void);
    const std::string &getName(void) const;
};