#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data d = {"Hello", 42, "World"};
    uintptr_t raw = Serializer::serialize(&d);
    Data *d2 = Serializer::deserialize(raw);

    std::cout << ">=== original ===<" << std::endl;
    std::cout << "(&d)->s1: " << (&d)->s1 << std::endl;
    std::cout << "(&d)->n: " << (&d)->n << std::endl;
    std::cout << "(&d)->s2: " << (&d)->s2 << std::endl;

    std::cout << ">=== serialized ===<" << std::endl;
    std::cout << "d2->s1: " << d2->s1 << std::endl;
    std::cout << "d2->n: " << d2->n << std::endl;
    std::cout << "d2->s2: " << d2->s2 << std::endl;
    return 0;
}