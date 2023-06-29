#pragma once

#include "Weapon.hpp"

class HumanB
{
  private:
    std::string name;
    Weapon *weapon;
    HumanB(void);

  public:
    HumanB(const std::string name);
    void setWeapon(Weapon &weapon);
    void attack(void) const;
};