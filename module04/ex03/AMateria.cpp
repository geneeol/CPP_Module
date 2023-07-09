#include "AMateria.hpp"

AMateria::AMateria() : type("default") {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria::~AMateria() {}

// TODO: *ice = *cure 테스트 해볼 것
AMateria &AMateria::operator=(const AMateria &other)
{
    type = other.type;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}