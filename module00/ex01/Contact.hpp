#pragma once

#include <string>
class Contact
{
  private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecrest;

  public:
    Contact();
    ~Contact();
    void setInfo(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret);
    std::string &getFirstName(void);
    std::string &getLastName(void);
    std::string &getNickname(void);
    void printInfo(void);
};