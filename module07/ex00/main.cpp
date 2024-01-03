#include "whatever.hpp"
#include <iostream>
#include <stdio.h>

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    const int e = 42;
    const int f = 21;
    const std::string g = "chaine3";
    const std::string h = "chaine4";

    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min(g, h) << std::endl;
    std::cout << "max( g, h ) = " << ::max(g, h) << std::endl;

    // std::string *str1 = new std::string("str1");
    // std::string *str2 = new std::string("str2");

    // printf("str1 = %p, str2 = %p\n", str1, str2);
    // swap(str1, str2);
    // std::cout << "str1 = " << *str1 << ", str2 = " << *str2 << std::endl;
    // printf("str1 = %p, str2 = %p\n", str1, str2);

    return 0;
}