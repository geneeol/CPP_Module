#include "AMateria.hpp"

AMateria::AMateria() : type("default") {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
    *this = other;
}

AMateria::~AMateria() {}

// myice = mycure 호출해도 타입은 변하지 않음
// 디폴트 복사 할당 연산자는 타입을 복사해버리므로 값이 변경됨
AMateria &AMateria::operator=(const AMateria &other)
{
    // type은 생성될 때 결정되고 이후에 변하지 않음.
    (void)other;
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