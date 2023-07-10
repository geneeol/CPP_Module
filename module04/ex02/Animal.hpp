#pragma once

#include <string>

class Animal
{
  private:
    Animal();

  protected:
    Animal(std::string type);
    Animal(const Animal &other);
    std::string type;

  public:
    Animal &operator=(const Animal &other);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const = 0;
    virtual void think() const = 0;
    virtual void addIdea(const std::string &idea) = 0;
};