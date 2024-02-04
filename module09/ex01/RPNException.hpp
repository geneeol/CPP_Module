#pragma once

#include <exception>
#include <string>

class RPNException : public std::exception
{
  public:
    RPNException(const std::string &msg) throw();
    virtual ~RPNException() throw();
    virtual const char *what() const throw();

  private:
    std::string msg;
};