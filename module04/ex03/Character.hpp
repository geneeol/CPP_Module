#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
    std::string name;
    const static int INVENTORY_CAPACITY = 4;
    const static int INITIAL_CAPACITY = 10;
    int unequipedCapacity;
    int unequipedCount;
    AMateria *inventory[INVENTORY_CAPACITY];
    AMateria **unequipedList;
    Character();

  public:
    Character(const std::string &name);
    Character(const Character &other);
    ~Character();
    Character &operator=(const Character &other);

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void addUnequiped(AMateria *m);
    void use(int idx, ICharacter &target);
    void printEquiped() const;
    void printUnquiped() const;
};
