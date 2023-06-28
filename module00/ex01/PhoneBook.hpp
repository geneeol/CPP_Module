
#pragma once

#define MAX_CONTACTS 8

#include "Contact.hpp"

class PhoneBook
{
  private:
    Contact contacts[MAX_CONTACTS];
    int nContacts;
    int nextIndex;

  public:
    PhoneBook();
    ~PhoneBook();
    void addContact(void);
    void searchContact(void);
    void printAllContact(void);
    void printContact(const int index);
    std::string formatter(const std::string &str);
};