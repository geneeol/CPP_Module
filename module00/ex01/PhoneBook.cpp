#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

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

    std::cout << "Enter a first name: ";
    std::cin >> firstName;
    std::cout << "Enter a last name: ";
    std::cin >> lastName;
    std::cout << "Enter a nickname: ";
    std::cin >> nickname;
    std::cout << "Enter a phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter the darkest secret";
    std::cin.ignore();
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
    // TODO: COL_WIDTH 출력 형식 고려할 것
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

    std::cout << "debug: " << maxSize << std::endl;
    printAllContact();
    std::cout << "Enter an index: ";
    std::cin >> idx;
    if (std::cin.fail())
    {
        std::cout << "Invalid type: index must be an integer" << std::endl;
        std::cin.clear();
        std::cin.ignore(maxSize, '\n');
        return;
    }
    if (idx < 0 || idx >= nContacts)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    contacts[idx].printInfo();
}