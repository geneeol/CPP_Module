#include "Fixed.hpp"
#include <cmath>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    val = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    val = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// 컴파일러 및 다른 플랫폼에서 일관되게 동작하려면 음수일 때 쉬프트 연산자를
// 사용하지 않는 것이 바람직하다
Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    this->val = val * (1 << fracBits);
}

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;
    this->val = roundf(val * (1 << fracBits));
}

int Fixed::getRawBits(void) const
{
    return (val);
}

void Fixed::setRawBits(int const raw)
{
    val = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)val / (1 << fracBits));
}

// 컴파일러 및 다른 플랫폼에서 일관되게 동작하려면 음수일 때 쉬프트 연산자를
// 사용하지 않는 것이 바람직하다
int Fixed::toInt(void) const
{
    return (val / (1 << fracBits));
}