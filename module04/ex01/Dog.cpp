#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("defaultDog"), brain(new Brain())
{
    std::cout << "Dog: no argumtent constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type), brain(new Brain())
{
    std::cout << "Dog: string constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog: copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: assignment operator called" << std::endl;
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Dog: " << type << " woof woof" << std::endl;
}

void Dog::think() const
{
    std::cout << "Dog: " << type << " is thinking about:" << std::endl;
    for (int i = 0; i < brain->getSize(); i++)
    {
        std::cout << i << "th idea: " << brain->getIdea(i) << std::endl;
    }
}

void Dog::addIdea(const std::string &idea)
{
    brain->addIdea(idea);
}