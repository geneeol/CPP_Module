#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("defaultCat"), brain(new Brain())
{
    std::cout << "Cat: no argumtent constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type), brain(new Brain())
{
    std::cout << "Cat: string constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat: copy constructor called" << std::endl;
}

// 그 어떤 상황에서도 객체의 brain 포인터 맴버변수가 널일 수는 없다.
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Cat: " << type << " meow meow" << std::endl;
}

void Cat::think() const
{
    std::cout << "Cat: " << type << " is thinking about:" << std::endl;
    for (int i = 0; i < brain->getSize(); i++)
    {
        std::cout << i << "th idea: " << brain->getIdea(i) << std::endl;
    }
}

void Cat::addIdea(const std::string &idea)
{
    brain->addIdea(idea);
}