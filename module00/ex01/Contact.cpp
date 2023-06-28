#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecrest = "";
}

void Contact::setInfo(std::string firstName, std::string lastName,
                      std::string nickname, std::string phoneNumber,
                      std::string darkSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecrest = darkSecret;
}

std::string &Contact::getFirstName(void)
{
    return (firstName);
}

std::string &Contact::getLastName(void)
{
    return (lastName);
}

std::string &Contact::getNickname(void)
{
    return (nickName);
}

void Contact::printInfo(void)
{
    std::cout << "First name: " << firstName << std::endl
              << "Last name: " << lastName << std::endl
              << "Nickname: " << nickName << std::endl
              << "Phone number: " << phoneNumber << std::endl
              << "darkest secret: " << darkestSecrest << std::endl;
}