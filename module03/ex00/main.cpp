#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap obj1("obj1");
    ClapTrap obj2("obj2");

    std::cout << "\n";
    std::cout << "obj1's energy point: " << obj1.getEnergyPoints() << std::endl;
    obj1.attack("obj2");
    std::cout << "obj1's energy point after attacking: "
              << obj1.getEnergyPoints() << std::endl;
    obj2.takeDamage(obj1.getAttackDamage());
    std::cout << "obj2's hitPoints after being attacked: "
              << obj2.getHitPoints() << "\n\n";
    obj2.beRepaired(5);
    std::cout << "obj2's hitPoints after being repaired: "
              << obj2.getHitPoints() << "\n\n";
    for (int i = 0; i < 10; i++)
        obj1.attack("obj2");
    std::cout << "\n";

    obj2.takeDamage(5);
    std::cout << "obj2's hitPoints after taking damage: " << obj2.getHitPoints()
              << "\n\n";

    obj2.takeDamage(100);
    std::cout << "obj2's hitPoints after taking damage: " << obj2.getHitPoints()
              << std::endl;
    obj2.attack("obj1");
    obj2.beRepaired(10);
    return (0);
}