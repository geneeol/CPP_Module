#include "MateriaSource.hpp"
#include <iostream>

#define DISPLAY std::cout << "MateriaSource: "

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        sourceList[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    // 널로 초기화 되는 부분 없으면 쓰레기값을 delete하는 문제 발생
    for (int i = 0; i < 4; i++)
        sourceList[i] = NULL;
    *this = other;
}

// TODO: 만약 이미 리스트에 있는 materia를 learnMateria에 또 추가하려고 한다면
// double delete 문제가 발생할 수 있다.
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete sourceList[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this == &other)
        return *this;
    for (int i = 0; i < 4; i++)
    {
        delete sourceList[i];
        sourceList[i] = NULL;
        if (other.sourceList[i])
            sourceList[i] = other.sourceList[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        DISPLAY;
        std::cout << "Learn fail: Invalid materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!sourceList[i])
        {
            sourceList[i] = m;
            DISPLAY;
            std::cout << "Learn success: type: " << m->getType() << std::endl;
            return;
        }
    }
    delete m;
    DISPLAY;
    std::cout << "Learn fail: sourceList is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (sourceList[i] && sourceList[i]->getType() == type)
        {
            DISPLAY;
            std::cout << "Create success: type: " << type << std::endl;
            return sourceList[i]->clone();
        }
    }
    DISPLAY;
    std::cout << "Create fail: Invalid type" << std::endl;
    return NULL;
}