#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat: no argumtent constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal("Cat_" + type)
{
    std::cout << "Cat: string constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat: copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    Animal::operator=(other);
    std::cout << "Cat: assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: " << type << " meow meow" << std::endl;
}