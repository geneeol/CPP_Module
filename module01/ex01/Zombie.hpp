#pragma once

#include <iostream>

class Zombie
{
  private:
    std::string name;

  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void) const;
    void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);
