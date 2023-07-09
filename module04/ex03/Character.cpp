#include "Character.hpp"
#include <iostream>

#define DISPLAY std::cout << "Character: " << name << " "

Character::Character() {}

Character::Character(const std::string &name)
    : name(name), unequipedCapacity(INITIAL_CAPACITY), unequipedCount(0),
      unequipedList(new AMateria *[INITIAL_CAPACITY])
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &other) : unequipedList(NULL)
// : unequipedCapacity(0), unequipedCount(0), unequipedList(NULL)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    *this = other;
}

Character::~Character()
{
    int i;

    for (i = 0; i < INVENTORY_CAPACITY; i++)
        delete inventory[i];
    for (i = 0; i < unequipedCount; i++)
        delete unequipedList[i];
    delete[] unequipedList;
}

Character &Character::operator=(const Character &other)
{
    int i;

    std::cout << "Character: " << name << " operator= called\n";
    if (this == &other)
        return (*this);
    name = other.name;
    for (i = 0; i < INVENTORY_CAPACITY; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
    if (unequipedList)
    {
        for (i = 0; i < unequipedCount; i++)
            delete unequipedList[i];
        delete[] unequipedList;
    }
    unequipedCapacity = other.unequipedCapacity;
    unequipedCount = other.unequipedCount;
    unequipedList = new AMateria *[unequipedCapacity];
    for (i = 0; i < unequipedCount; i++)
        unequipedList[i] = other.unequipedList[i]->clone();
    return (*this);
}

const std::string &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        DISPLAY;
        std::cout << "equip fail: Invalid materia" << std::endl;
        return;
    }
    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            DISPLAY;
            std::cout << "equip success: type: " << m->getType() << std::endl;
            return;
        }
    }
    delete m;
    DISPLAY;
    std::cout << "equip fail: Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= INVENTORY_CAPACITY)
    {
        DISPLAY;
        std::cout << "unequip fail: index is out of range" << std::endl;
        return;
    }
    if (!inventory[idx])
    {
        DISPLAY;
        std::cout << "unequip fail: No materia in this slot" << std::endl;
        return;
    }
    DISPLAY;
    std::cout << "unequip success: type: " << inventory[idx]->getType()
              << std::endl;
    addUnequiped(inventory[idx]);
    inventory[idx] = NULL;
}

void Character::addUnequiped(AMateria *m)
{
    if (unequipedCount == unequipedCapacity)
    {
        AMateria **newUnequipedList = new AMateria *[unequipedCapacity * 2];
        for (int i = 0; i < unequipedCount; i++)
            newUnequipedList[i] = unequipedList[i];
        delete[] unequipedList;
        unequipedList = newUnequipedList;
        unequipedCapacity *= 2;
    }
    unequipedList[unequipedCount++] = m;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= INVENTORY_CAPACITY)
    {
        DISPLAY;
        std::cout << "use fail: index is out of range" << std::endl;
        return;
    }
    if (!inventory[idx])
    {
        DISPLAY;
        std::cout << "use fail: No materia in this slot" << std::endl;
        return;
    }
    inventory[idx]->use(target);
}

void Character::printEquiped() const
{
    DISPLAY;
    std::cout << "Equiped: ";
    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        if (inventory[i])
            std::cout << inventory[i]->getType() << " ";
    }
    std::cout << std::endl;
}

void Character::printUnquiped() const
{
    DISPLAY;
    std::cout << "Unequiped: ";
    for (int i = 0; i < unequipedCount; i++)
        std::cout << unequipedList[i]->getType() << " ";
    std::cout << std::endl;
}