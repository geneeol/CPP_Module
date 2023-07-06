#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "No argument constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "string argument constructor called" << std::endl;
    std::cout << "name: " << name << ", hitPoints: " << hitPoints
              << ", energyPoints: " << energyPoints
              << ", attackDamage: " << attackDamage << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
    : name(clapTrap.name), hitPoints(clapTrap.hitPoints),
      energyPoints(clapTrap.energyPoints), attackDamage(clapTrap.attackDamage)
{
    std::cout << "copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "copy assignment operator called" << std::endl;
    name = clapTrap.name;
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attackDamage << " points of damage!" << std::endl;
    --energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage!" << std::endl;
    hitPoints >= amount ? hitPoints -= amount : hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " is repaired for " << amount
              << " points!" << std::endl;
    hitPoints += amount;
    --energyPoints;
}

const std::string &ClapTrap::getName() const
{
    return (name);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}