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
    val = fixed.getRawBits();
}

// TODO: 출력문 과제와 다른 점 찾기
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

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    this->val = val << fracBits;
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
    return (static_cast<float>(val) / (1 << fracBits));
}

int Fixed::toInt(void) const
{
    return (val >> fracBits);
}