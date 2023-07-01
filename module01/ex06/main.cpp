#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cerr << "Usage: harl <log level>" << std::endl;
        return (1);
    }
    harl.complain(std::string(argv[1]));
    return (0);
}