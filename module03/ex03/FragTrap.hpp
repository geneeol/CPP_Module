#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  private:
    FragTrap();

  public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys(void);
    void printInfo(void);
};
