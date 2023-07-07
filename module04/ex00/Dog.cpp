#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("defaultDog")
{
    std::cout << "Dog: no argumtent constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
    std::cout << "Dog: string constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog: copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    std::cout << "Dog: assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: " << type << " woof woof" << std::endl;
}