#include "BitcoinExchange.hpp"
#include <iostream>

int main(void)
{
    BitcoinExchange *exchanger;

    try
    {
        exchanger = new BitcoinExchange("data.csv");
    }
    catch (std::exception &e)
    {
        std::cout << "Failed to open file" << std::endl;
    }
    exchanger->fillDbMap();
    exchanger->printDbMap();
    delete exchanger;
    return 0;
}