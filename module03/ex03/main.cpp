#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap obj1("obj1");
    FragTrap obj2("obj2");

    obj1.printInfo();
    obj2.printInfo();

    std::cout << std::endl;
    obj1.attack("obj2");
    obj2.takeDamage(obj1.getAttackDamage());
    obj2.printInfo();

    std::cout << std::endl;
    obj2.beRepaired(10);
    obj2.printInfo();

    std::cout << std::endl;
    obj1.highFivesGuys();
    return (0);
}