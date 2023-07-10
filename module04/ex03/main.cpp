#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define RED "\033[1;31m"
#define GREEN "\e[0;32m"
#define COLOR_RESET "\033[0m"
#define LF std::cout << std::endl

void test1()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    LF;
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void test2()
{
    MateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(NULL);
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());

    LF;
    MateriaSource src2 = *src;
    Character *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);

    Character *bob = new Character("bob");

    LF;
    tmp = src->createMateria("ice");
    bob->equip(tmp);
    tmp = src->createMateria("fire");
    bob->equip(tmp);
    bob->equip(new Ice());
    bob->equip(new Ice());
    bob->equip(new Ice());
    bob->equip(new Ice());
    std::cout << "bob's equiped list\n";
    bob->printEquiped();

    LF;
    std::cout << "After copy\n";
    *bob = *me;
    Character kang(*me);

    me->printEquiped();
    bob->printEquiped();
    kang.printEquiped();

    delete bob;
    delete me;
    delete src;
}

void test3()
{
    MateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    LF;
    Character *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    LF;
    std::cout << GREEN << "unequip test start\n";
    std::cout << COLOR_RESET;
    me->unequip(-10);
    me->unequip(5);
    me->unequip(3);
    me->unequip(0);
    me->unequip(1);
    me->unequip(0);

    LF;
    for (int i = 0; i < 12; i++)
    {
        me->equip(new Cure());
        me->unequip(i % 4);
    }
    me->printEquiped();
    me->printUnquiped();

    Character *bob = new Character("bob");

    LF;
    for (int i = 0; i < 12; i++)
    {
        bob->equip(new Ice());
        bob->unequip(i % 4);
    }
    bob->printEquiped();
    bob->printUnquiped();

    LF;
    std::cout << "After copy\n";
    *bob = *me;

    me->printEquiped();
    bob->printEquiped();
    me->printUnquiped();
    bob->printUnquiped();

    delete bob;
    delete me;
    delete src;
}

void test4()
{
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    std::cout << "ice type: " << ice->getType() << std::endl;
    std::cout << "cure type: " << cure->getType() << std::endl;

    std::cout << "After assing cure to ice\n";
    *ice = *cure;
    std::cout << "ice type: " << ice->getType() << std::endl;
    std::cout << "cure type: " << cure->getType() << std::endl;

    Character me("me");
    Character bob("bob");

    LF;
    me.equip(ice);
    bob.equip(cure);

    me.printEquiped();
    bob.printEquiped();

    // 동적 바인딩
    me.use(0, bob);
    bob.use(0, me);
}

// 릭검사 valgrind --leak-check=yes ./ex03
int main()
{
    std::cout << RED << "======= Basic test =======\n" << COLOR_RESET;
    test1();

    std::cout << RED << "\n\n======= Deep copy test =======\n" << COLOR_RESET;
    test2();

    std::cout << RED << "\n\n======= Unequip test =======\n" << COLOR_RESET;
    test3();

    std::cout << RED << "\n\n======= Assign test =======\n" << COLOR_RESET;
    test4();

    return 0;
}

// 릭검사 결과
// ==32265== Memcheck, a memory error detector
// ==32265== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==32265== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
// ==32265== Command: ./ex03
// ==32265==
// ======= basic test =======
// MateriaSource: Learn success: type: ice
// MateriaSource: Learn success: type: cure
// MateriaSource: Create success: type: ice
// Character: me equip success: type: ice
// MateriaSource: Create success: type: cure
// Character: me equip success: type: cure

// * shoots an ice bolt at bob *
// * heals bob's wounds *

// ======= deep copy test =======
// MateriaSource: Learn success: type: ice
// MateriaSource: Learn fail: Invalid materia
// MateriaSource: Learn success: type: cure
// MateriaSource: Learn success: type: ice
// MateriaSource: Learn success: type: ice
// MateriaSource: Learn fail: sourceList is full
// MateriaSource: Learn fail: sourceList is full

// MateriaSource: Create success: type: ice
// Character: me equip success: type: ice
// MateriaSource: Create success: type: cure
// Character: me equip success: type: cure
// MateriaSource: Create fail: Invalid type
// Character: me equip fail: Invalid materia

// MateriaSource: Create success: type: ice
// Character: bob equip success: type: ice
// MateriaSource: Create fail: Invalid type
// Character: bob equip fail: Invalid materia
// Character: bob equip success: type: ice
// Character: bob equip success: type: ice
// Character: bob equip success: type: ice
// Character: bob equip fail: Inventory is full
// bob's equiped list
// Character: bob Equiped: ice ice ice ice

// After copy
// Character: bob operator= called
// Character:  operator= called
// Character: me Equiped: ice cure
// Character: me Equiped: ice cure
// Character: me Equiped: ice cure

// ======= unequip test =======
// MateriaSource: Learn success: type: ice
// MateriaSource: Learn success: type: cure
// MateriaSource: Learn success: type: ice
// MateriaSource: Learn success: type: cure

// MateriaSource: Create success: type: ice
// Character: me equip success: type: ice
// MateriaSource: Create success: type: ice
// Character: me equip success: type: ice

// unequip test start
// Character: me unequip fail: index is out of range
// Character: me unequip fail: index is out of range
// Character: me unequip fail: No materia in this slot
// Character: me unequip success: type: ice
// Character: me unequip success: type: ice
// Character: me unequip fail: No materia in this slot

// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip fail: No materia in this slot
// Character: me equip success: type: cure
// Character: me unequip fail: No materia in this slot
// Character: me equip success: type: cure
// Character: me unequip fail: No materia in this slot
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me equip success: type: cure
// Character: me unequip success: type: cure
// Character: me Equiped: cure cure cure
// Character: me Unequiped: ice ice cure cure cure cure cure cure cure cure cure

// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip fail: No materia in this slot
// Character: bob equip success: type: ice
// Character: bob unequip fail: No materia in this slot
// Character: bob equip success: type: ice
// Character: bob unequip fail: No materia in this slot
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob equip success: type: ice
// Character: bob unequip success: type: ice
// Character: bob Equiped: ice ice ice
// Character: bob Unequiped: ice ice ice ice ice ice ice ice ice

// After copy
// Character: bob operator= called
// Character: me Equiped: cure cure cure
// Character: me Equiped: cure cure cure
// Character: me Unequiped: ice ice cure cure cure cure cure cure cure cure cure
// Character: me Unequiped: ice ice cure cure cure cure cure cure cure cure cure
// ==32265==
// ==32265== HEAP SUMMARY:
// ==32265==     in use at exit: 0 bytes in 0 blocks
// ==32265==   total heap usage: 90 allocs, 90 frees, 78,096 bytes allocated
// ==32265==
// ==32265== All heap blocks were freed -- no leaks are possible
// ==32265==
// ==32265== For lists of detected and suppressed errors, rerun with: -s
// ==32265== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)