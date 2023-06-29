#include "Zombie.hpp"

int main(void)
{
    const int nZombie = 5;
    Zombie *horde = zombieHorde(nZombie, "Zombie");

    for (int i = 0; i < nZombie; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}