#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *brain;

  public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void makeSound() const;
    void think() const;
    void addIdea(const std::string &idea);
};