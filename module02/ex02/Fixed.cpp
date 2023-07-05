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
    val = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    val = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int val)
{
    this->val = val * (1 << fracBits);
}

Fixed::Fixed(const float val)
{
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
    // std::cout << "toFloat, val: " << val << std::endl;
    // return (static_cast<float>(val) / (1 << fracBits));
    return ((float)val / (1 << fracBits));
}

int Fixed::toInt(void) const
{
    return (val / (1 << fracBits));
}

/******ex02에서 추가한 함수 *******/

bool Fixed::operator>(const Fixed &fixed) const
{
    return (val > fixed.val);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (val < fixed.val);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (val >= fixed.val);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (val <= fixed.val);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (val == fixed.val);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (val != fixed.val);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed tmp;

    tmp.setRawBits(val + fixed.val);
    return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed tmp;

    tmp.setRawBits(val - fixed.val);
    return (tmp);
}

// long long으로 형변환 해야 오버플로우로 인한 precision loss를 방지할 수 있다.
int Fixed::fixedMul(long long a, long long b)
{
    return ((a * b) / (1 << fracBits));
}

int Fixed::fixedDiv(long long a, long long b)
{
    return (a * (1 << fracBits) / b);
}

// 주로 1번 링크를 참고하여 구현
// https://spin.atomicobject.com/2012/03/15/simple-fixed-point-math/
// https://stackoverflow.com/questions/14008330/how-do-you-multiply-two-fixed-point-numbers
// https://en.wikipedia.org/wiki/Fixed-point_arithmetic#Multiplication
Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed tmp;

    tmp.setRawBits(fixedMul(val, fixed.val));
    return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed tmp;

    tmp.setRawBits(fixedDiv(val, fixed.val));
    return (tmp);
}

Fixed &Fixed::operator++()
{
    ++val;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++val;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    --val;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --val;
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a <= b ? a : b);
}

// https://stackoverflow.com/questions/19554841/how-to-use-const-cast
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a <= b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a >= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a >= b ? a : b);
}