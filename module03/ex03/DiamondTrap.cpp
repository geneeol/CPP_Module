#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(""), ScavTrap(""), FragTrap("")
{
    std::cout << "DiamondTrap: no argument constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name),
      FragTrap(name), name(name)
{
    std::cout << "DiamondTrap: string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other.name + "_clap_name", other.hitPoints, other.energyPoints,
               other.attackDamage),
      ScavTrap(other.name), FragTrap(other.name), name(other.name)
{
    std::cout << "DiamondTrap: copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    ClapTrap::operator=(other);
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    name = other.name;
    std::cout << "DiamondTrap: copy assignment operator called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    // DiamondTrap의 맴버일 것임.
    std::cout << "DiamondTrap: " << name << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap: name: " << name
              << ", ClapTrap: name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::printInfo(void)
{
    std::cout << "DiamondTrap: name: " << name
              << ", clapTrap's name: " << ClapTrap::name
              << ", hitPoints: " << hitPoints
              << ", energyPoints: " << energyPoints
              << ", attackDamage: " << attackDamage << std::endl;
}

// -Wshadow 옵션을 사용해도 warning이 발생하지 않는다.
const std::string &DiamondTrap::getName(void) const
{
    return (name);
}