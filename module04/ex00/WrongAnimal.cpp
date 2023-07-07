#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("default")
{
    std::cout << "WrongAnimal: no argumtent constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal: string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal: assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal: This sound won't be overriden" << std::endl;
}