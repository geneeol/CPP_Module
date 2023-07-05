#include "Fixed.hpp"
#include <iostream>

void test(Fixed c, Fixed d)
{
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;

    std::cout << "c + d: " << (c + d) << std::endl;
    std::cout << "c - d: " << (c - d) << std::endl;
    std::cout << "c * d: " << (c * d) << std::endl;
    std::cout << "c / d: " << (c / d) << std::endl << std::endl;
}

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << ">==== Basic test <====" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    // std::cout << Fixed::min(a, b) << std::endl;
    std::cout << ">=====================<\n" << std::endl;
    std::cout << ">==== Additional test <====" << std::endl;

    // 0으으로  나누면 floating exception
    test(Fixed(5), Fixed(2));
    test(Fixed(2), Fixed(5));
    // a^2에 대한 오버플로우 경계값 a=2896
    test(Fixed(2896), Fixed(2896));
    test(Fixed(2897), Fixed(2897));

    return 0;
}
