#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

static void convertChar(double d)
{
    std::cout << "char: ";
    if (d != d || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if ((d >= 0 && d <= 31) || d == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void convertInt(double d)
{
    std::cout << "int: ";
    if (d != d || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

static int getPrecision(double d)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << d;
    std::string str = oss.str();
    size_t dotPos = str.find('.');
    int precision;

    if (dotPos == std::string::npos)
        return 1;

    precision = str.size() - dotPos - 1;
    for (size_t i = str.size() - 1; i > dotPos; i--)
    {
        if (str[i] == '0')
            --precision;
        else
            break;
    }
    return precision == 0 ? 1 : precision;
}

static void convertFloat(double d)
{
    int precision;

    std::cout << "float: ";

    if (d != d || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
    {
        if (d > 0)
            std::cout << "+";
        std::cout << static_cast<float>(d) << "f" << std::endl;
        return;
    }
    else
    {
        precision = getPrecision(d);
        std::cout << std::fixed;
        if (precision < std::cout.precision())
            std::cout << std::setprecision(precision);
        std::cout << static_cast<float>(d) << "f" << std::endl;
        std::cout << std::defaultfloat;
    }
}

static void convertDouble(double d)
{
    int precision;

    std::cout << "double: ";
    if (d != d || d == std::numeric_limits<double>::infinity())
    {
        if (d > 0)
            std::cout << "+";
        std::cout << d << std::endl;
        return;
    }
    precision = getPrecision(d);
    std::cout << std::fixed << std::setprecision(precision) << d << std::endl;
    std::cout << std::defaultfloat;
}

static bool mayBeImpossible(const std::string &str)
{
    return (str[0] == '\0' || str.length() >= 2);
}

static bool invalidFormat(const std::string &str, const std::string str_end, double d)
{
    if (str_end[0] == '\0')
        return false;
    if (str.find('.') != std::string::npos)
        return (!(str_end[0] == 'f' && str_end[1] == '\0'));
    if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || d != d)
        return (!(str_end[0] == 'f' && str_end[1] == '\0'));
    return true;
}

void ScalarConverter::convert(const std::string &str)
{
    char *str_end;
    double d = strtod(str.c_str(), &str_end);

    // str_end가 널문자라면 not impossible
    // str_end가 f이고 그 다음이 널문자라면 not impossible
    // 변환한 d가 nan인데 str_end가 널문자가 아니라면 not impossible
    // 위 세상황이 아니라면 전부 impossible
    // 추가로 빈문자열일 경우 impossible
    if (mayBeImpossible(str) && invalidFormat(str, str_end, d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // a, * 같은 게 인풋으로 들어왔을 때 이를 char 그 자체 값으로 해석
    if (str.length() == 1 && d == 0 && str[0] != '0')
        d = static_cast<double>(str[0]);
    convertChar(d);
    convertInt(d);
    convertFloat(d);
    convertDouble(d);
}
