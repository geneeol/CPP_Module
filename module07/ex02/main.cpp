#include "Array.hpp"

#include <iostream>

int main(void)
{
    Array<int> intArr(5);
    Array<std::string> strArr(5);

    std::cout << "intArr size: " << intArr.size() << std::endl;
    std::cout << "strArr size: " << strArr.size() << std::endl;

    for (unsigned int i = 0; i < intArr.size(); i++)
        intArr[i] = i;
    for (unsigned int i = 0; i < strArr.size(); i++)
        strArr[i] = std::to_string(i);

    std::cout << "intArr: ";
    for (unsigned int i = 0; i < intArr.size(); i++)
        std::cout << intArr[i] << " ";
    std::cout << std::endl;
    std::cout << "strArr: ";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;

    try
    {
        std::cout << "intArr[5]: " << intArr[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "intArr[5]: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "strArr[5]: " << strArr[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "strArr[5]: " << e.what() << std::endl;
    }
    std::cout << "\n\n\n";

    const Array<int> intArr2(5);
    const Array<std::string> strArr2(5);

    std::cout << "intArr2 size: " << intArr2.size() << std::endl;
    std::cout << "strArr2 size: " << strArr2.size() << std::endl;

    std::cout << "intArr2: ";
    for (unsigned int i = 0; i < intArr2.size(); i++)
        std::cout << intArr2[i] << " ";
    // intArr2[0] = 1;
    std::cout << std::endl;
    std::cout << "strArr2: ";
    for (unsigned int i = 0; i < strArr2.size(); i++)
        std::cout << strArr2[i] << " ";
    std::cout << std::endl;

    try
    {
        std::cout << "intArr2[5]: " << intArr2[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "intArr2[5]: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "strArr2[5]: " << strArr2[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "strArr2[5]: " << e.what() << std::endl;
    }

    return (0);
}