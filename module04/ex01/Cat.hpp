#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain *brain;

  public:
    Cat();
    Cat(const std::string &type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void makeSound() const;
    void think() const;
    void addIdea(const std::string &idea);
};