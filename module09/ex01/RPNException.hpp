#pragma once

#include <exception>
#include <string>

class RPNException : public std::exception
{
  private:
    std::string msg;

  public:
    RPNException(const std::string &msg) throw();
    virtual ~RPNException() throw();
    virtual const char *what() const throw();
};