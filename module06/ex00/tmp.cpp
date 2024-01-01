#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

int main(void)
{
    char *endptr;
    double d1 = strtod("inf", &endptr);
    std::cout << ">=== convert inf <===" << std::endl;
    std::cout << d1 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    double d2 = strtod("inff", &endptr);
    std::cout << ">=== convert inff <===" << std::endl;
    std::cout << d2 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    double d3 = strtod("-inf", &endptr);
    std::cout << ">=== convert -inf <===" << std::endl;
    std::cout << d3 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    double d4 = strtod("4.2f", &endptr);
    std::cout << ">=== convert 4.2f <===" << std::endl;
    std::cout << d4 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    double d5 = strtod("0.0", &endptr);
    std::cout << ">=== convert 0.0 <===" << std::endl;
    std::cout << d5 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    double d6 = strtod("a", &endptr);
    std::cout << ">=== convert a <===" << std::endl;
    std::cout << d6 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    double d7 = strtod("nan", &endptr);
    std::cout << ">=== convert nan <===" << std::endl;
    std::cout << d7 << std::endl;
    std::cout << endptr << std::endl;
    std::cout << "\n\n";

    std::cout << std::numeric_limits<float>::max() << std::endl;
    std::cout << std::numeric_limits<float>::min() << std::endl;

    return (0);
}