#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>

// TODO: nanf 이렇게 들어오면 에러로 처리가 안된다...
// inff 이런건 자연스럽게 돼
void ScalarConverter::convert(const std::string &str)
{
    char *str_end;
    double d = strtod(str.c_str(), &str_end);

    // 길이 1짜리 따로 검사하고
    // char 처리할라고

    // 에러가 아닌 경우
    // 1. 널문자일때, str_end가 f를 가리키고 바로 뒤가 널문자일 때
    // 그외 에러

    // 무조건 에러인 상황
    if (str.length() >= 2 &&
        !(str_end[0] == '\0' || (str_end[0] == 'f' && str_end[1] == '\0')))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    // TODO: double로 변환한 후에 그 후에 각각으로 변환하는 시도를 해도
    // 괜찮나..?
    if (str.length() == 1 && d == 0 && str[0] != '0')
        d = static_cast<double>(str[0]);
    ScalarConverter::convertChar(d);
    ScalarConverter::convertInt(d);
    ScalarConverter::convertFloat(d);
    ScalarConverter::convertDouble(d);
}

void ScalarConverter::convertChar(double d)
{
    std::cout << "char: ";
    if (d != d || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if ((d >= 0 && d <= 32) || d == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::convertInt(double d)
{
    std::cout << "int: ";
    if (d != d || d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

void ScalarConverter::convertFloat(double d)
{
    std::cout << "float: ";
    if (d < -std::numeric_limits<float>::max() ||
        d > std::numeric_limits<float>::max())
        std::cout << "inf" << std::endl;
    else if (d != d)
        std::cout << "nan" << std::endl;
    else
        std::cout << static_cast<float>(d) << "f" << std::endl;
}