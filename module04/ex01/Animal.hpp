#pragma once

#include <string>

class Animal
{
  protected:
    std::string type;

  public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const;
    virtual void think() const = 0;
    virtual void addIdea(const std::string &idea) = 0;
};