#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
  private:
    std::string name;
    DiamondTrap();

  public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void whoAmI(void);
    void printInfo(void);
}