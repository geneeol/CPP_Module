#include "Array.hpp"
#include <iostream>
#include <sstream>

int main(void)
{
    Array<int> intArr(5);
    Array<std::string> strArr(5);

    std::cout << "intArr size: " << intArr.size() << std::endl;
    std::cout << "strArr size: " << strArr.size() << std::endl;

    for (unsigned int i = 0; i < intArr.size(); i++)
        intArr[i] = i;
    for (unsigned int i = 0; i < strArr.size(); i++)
    {
        std::ostringstream convert;
        convert << i;
        strArr[i] = convert.str();
    }

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

    try
    {
        std::cout << "intArr[-1]: " << intArr[-1] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "intArr[-1]: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n\n\n";

    const Array<int> intArr2(5);
    const Array<std::string> strArr2(5);

    std::cout << "intArr2 size: " << intArr2.size() << std::endl;
    std::cout << "strArr2 size: " << strArr2.size() << std::endl;

    std::cout << "intArr2: ";
    for (unsigned int i = 0; i < intArr2.size(); i++)
        std::cout << intArr2[i] << " ";
    std::cout << std::endl;
    std::cout << "strArr2: ";
    for (unsigned int i = 0; i < strArr2.size(); i++)
        std::cout << strArr2[i] << " ";
    std::cout << std::endl;

    return (0);
}

// #include "Array.hpp"
// #include <iostream>

// #define MAX_VAL 750
// int main(int, char **)
// {
//     Array<int> numbers(MAX_VAL);
//     int *mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     // SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete[] mirror;
//     return 0;
// }