#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ScavTrap obj1("obj1");
    ScavTrap obj2("obj2");

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
    obj1.guardGate();
    return (0);
}