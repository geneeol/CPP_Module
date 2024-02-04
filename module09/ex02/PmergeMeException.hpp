#pragma once

#include <exception>
#include <string>

class PmergeMeException : public std::exception
{
  private:
    std::string msg;

  public:
    PmergeMeException(const std::string &msg) throw();
    virtual ~PmergeMeException() throw();
    virtual const char *what() const throw();
};