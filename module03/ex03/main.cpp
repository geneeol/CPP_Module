#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "====== basic test ======\n";
    {
        DiamondTrap obj1("obj1");

        std::cout << std::endl;
        obj1.whoAmI();
        obj1.printInfo();

        std::cout << std::endl;
        obj1.attack("target");

        std::cout << std::endl;
        obj1.guardGate();
        obj1.highFivesGuys();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\n====== shadow test ======\n";
    {
        DiamondTrap obj1("obj1");

        std::cout << "my name is " << obj1.getName() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\n====== previous test ======\n";
    {
        DiamondTrap obj1("obj1");
        DiamondTrap obj2("obj2");

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
        obj1.guardGate();
        std::cout << std::endl;
    }
}