#include "Point.hpp"
#include "bsp.h"
#include <iostream>

void test(Point const a, Point const b, Point const c, Point const point)
{
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "point: " << point << std::endl;
    std::cout << "isPointInTriangle: " << bsp(a, b, c, point) << "\n\n";
}

int main(void)
{
    std::cout << "=== test1 point is in triangle ===\n";
    test(Point(0, 0), Point(3, 0), Point(3, 3), Point(0.5, 0.2));
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(0.5, 0.2));
    test(Point(0, 10.5), Point(-10.5, -10.5), Point(20.5, -11.5), Point(0, -3));
    test(Point(0, 10.5), Point(-10.5, -10.5), Point(20.5, -11.5),
         Point(3.5, 2.24));
    std::cout << "\n=== test2 point is on edge ===\n";
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(1, 1));
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(2, 0));
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(3, 2));
    std::cout << "\n=== test2 point is vertex ===\n";
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(3, 3));
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(0, 0));
    test(Point(0, 0), Point(3, 3), Point(3, 0), Point(3, 0));
}