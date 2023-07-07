#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
// : ClapTrap(), ScavTrap(), FragTrap()
{
    this->name = "default";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
// : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " is born!" << std::endl;
}