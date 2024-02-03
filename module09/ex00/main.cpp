#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    BitcoinExchange *exchanger;

    if (argc != 2)
    {
        std::cout << "Usage: ./ex00 input.txt" << std::endl;
        return 1;
    }

    try
    {
        exchanger = new BitcoinExchange(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }
    exchanger->fillDbMap();
    exchanger->calcAndPrint();
    delete exchanger;
    return 0;
}