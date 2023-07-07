#include "Brain.hpp"
#include <iostream>

Brain::Brain() : size(0)
{
    std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) : size(other.size)
{
    std::cout << "Brain: copy constructor called" << std::endl;
    for (int i = 0; i < other.size; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain: copy assignment operator called" << std::endl;
    size = other.size;
    for (int i = 0; i < other.size; i++)
        ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain: destructor called" << std::endl;
}

std::string Brain::getIdea(int idx) const
{
    return (ideas[idx]);
}

void Brain::addIdea(const std::string &idea)
{
    if (size >= MAX_IDEAS)
        std::cout << "There's no more space in the brain to a new idea"
                  << std::endl;
    else
        ideas[size++] = idea;
}

int Brain::getSize() const
{
    return (size);
}