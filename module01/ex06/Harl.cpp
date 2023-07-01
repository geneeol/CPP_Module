#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "[ DEBUG ] " << std::endl
              << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-specialketchup burger."
              << std::endl
              << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ] " << std::endl
              << "I cannot believe adding extra bacon costs more money."
              << std::endl
              << "You didn't put enough bacon in my burger!" << std::endl
              << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ] " << std::endl
              << "I think I deserve to have some extra bacon for free."
              << std::endl
              << "I've been coming for years whereas you started working here "
              << "since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ] " << std::endl
              << "This is unacceptable, I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break;
    }
    switch (i)
    {
        case 0:
            debug();
            __attribute__((fallthrough));
        case 1:
            info();
            __attribute__((fallthrough));
        case 2:
            warning();
            __attribute__((fallthrough));
        case 3:
            error();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
    }
}