#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    const static int CAPACITY = 4;
    AMateria *sourceList[CAPACITY];

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};
