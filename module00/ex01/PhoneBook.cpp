#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

#define SEP "|"
#define COL_WIDTH 10

PhoneBook::PhoneBook()
{
    nContacts = 0;
    nextIndex = 0;
}

void PhoneBook::addContact(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkSecret;
    std::string junk;

    std::cout << "Enter a first name: ";
    std::cin >> firstName;
    std::cout << "Enter a last name: ";
    std::cin >> lastName;
    std::cout << "Enter a nickname: ";
    std::cin >> nickname;
    std::cout << "Enter a phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter the darkest secret: ";
    getline(std::cin, junk);
    getline(std::cin, darkSecret);
    contacts[nextIndex++].setInfo(firstName, lastName, nickname, phoneNumber,
                                  darkSecret);
    if (nextIndex == MAX_CONTACTS)
        nextIndex = 0;
    if (nContacts != MAX_CONTACTS)
        nContacts++;
}

std::string PhoneBook::formatter(const std::string &str)
{
    if (str.length() >= COL_WIDTH)
        return (str.substr(0, COL_WIDTH - 1) + ".");
    return (str);
}

void PhoneBook::printAllContact(void)
{
    for (int i = 0; i < nContacts; i++)
    {
        std::cout << std::right << std::setw(COL_WIDTH) << i << SEP;
        std::cout << std::right << std::setw(COL_WIDTH)
                  << formatter(contacts[i].getFirstName()) << SEP;
        std::cout << std::right << std::setw(COL_WIDTH)
                  << formatter(contacts[i].getLastName()) << SEP;
        std::cout << std::right << std::setw(COL_WIDTH)
                  << formatter(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::searchContact(void)
{
    const size_t maxSize = std::numeric_limits<std::streamsize>::max();
    int idx;

    // 입력 1a, 7 a 등 처리하려면 getline으로 읽고 stoi구현하는 것이 바람직
    printAllContact();
    std::cout << "Enter an index: ";
    std::cin >> idx;
    while (std::cin.fail() && std::cin.eof() == false)
    {
        std::cout << "Invalid type: index must be an integer\n"
                  << "Try again" << std::endl;
        std::cin.clear();
        std::cin.ignore(maxSize, '\n');
        std::cin >> idx;
    }
    if (idx < 0 || idx >= nContacts)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    contacts[idx].printInfo();
}