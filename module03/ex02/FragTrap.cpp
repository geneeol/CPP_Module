#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
    std::cout << "FragTrap: no argument constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap: name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other.name, other.hitPoints, other.energyPoints,
               other.attackDamage)
{
    std::cout << "FragTrap: copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap: assignation operator called" << std::endl;
    // name = other.name;
    // hitPoints = other.hitPoints;
    // energyPoints = other.energyPoints;
    // attackDamage = other.attackDamage;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap: " << name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target << ", causing "
              << attackDamage << " points of damage!" << std::endl;
    --energyPoints;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}

void FragTrap::printInfo(void)
{
    std::cout << "FragTrap: name: " << name << ", hitPoints: " << hitPoints
              << ", energyPoints: " << energyPoints
              << ", attackDamage: " << attackDamage << std::endl;
}