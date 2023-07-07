#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("default")
{
    std::cout << "Animal: no argumtent constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal: string constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal: copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal: assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal: destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "Animal: This sound will be overriden" << std::endl;
}