#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;

    randomChump("Zombie1");
    randomChump("Zombie2");
    zombie = newZombie("Zombie3");
    zombie->announce();
    randomChump("Zombie4");
    delete zombie;
    return (0);
}