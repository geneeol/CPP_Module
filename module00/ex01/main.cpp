#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    // TODO: eof 처리
    while (true)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (std::cin.eof())
        {
            std::cout << "EOF detected" << std::endl;
            break;
        }
        else if (command.compare("EXIT") == 0)
            break;
        else if (command.compare("ADD") == 0)
            phoneBook.addContact();
        else if (command.compare("SEARCH") == 0)
            phoneBook.searchContact();
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}