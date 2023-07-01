#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    // 수정하면 좋을 부분: cin은 whitespace를 기준으로 한 토큰씩 입력을 받는다.
    // 따라서 getline을 쓰거나 cin을 사용한 이후 ignore나 getline을 통해 버퍼를
    // 비우는 것이 바람직하다.
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