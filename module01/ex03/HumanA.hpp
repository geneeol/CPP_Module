#pragma once

#include "Weapon.hpp"

class HumanA
{
  private:
    std::string name;
    Weapon &weapon;
    HumanA(void);

  public:
    HumanA(std::string name, Weapon &weapon);
    void attack(void) const;
};