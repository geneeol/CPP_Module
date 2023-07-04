#include "Fixed.hpp"
#include <iostream>

// 소수점비트가 8번째 비트이므로 Fixed 클래스는 소수 log(2^8)자리까지 표현가능
// cout default precision이 유효숫자 6자리
int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "\n======================\n";

    Fixed e(299.123456789f);
    Fixed f(-10.5f);

    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;
    return 0;
}
