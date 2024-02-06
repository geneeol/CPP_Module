#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./ex00 input.txt" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange exchanger(argv[1]);
        exchanger.fillDbMap();
        exchanger.calcAndPrint();
    }
    catch (std::exception &e)
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }
    return 0;
}