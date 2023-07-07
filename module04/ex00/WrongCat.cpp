#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("defaultWrongCat")
{
    std::cout << "WrongCat: no argumtent constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
    std::cout << "WrongCat: string constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    WrongAnimal::operator=(other);
    std::cout << "WrongCat: assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: meow meow" << std::endl;
}