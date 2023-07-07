#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
    std::cout << "ScavTrap: no argument constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap: string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other.name, other.hitPoints, other.energyPoints,
               other.attackDamage)
{
    std::cout << "ScavTrap: copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap: copy assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap: " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attackDamage << " points of damage!" << std::endl;
    --energyPoints;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " has entered in Gate keeper mode"
              << std::endl;
}

void ScavTrap::printInfo(void)
{
    std::cout << "ScavTrap: name: " << name << ", hitPoints: " << hitPoints
              << ", energyPoints: " << energyPoints
              << ", attackDamage: " << attackDamage << std::endl;
}