#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form
{
  private:
    Form();
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    const static int HIGHEST_GRADE = 1;
    const static int LOWEST_GRADE = 150;
    Form &operator=(const Form &other);

  public:
    class GradeTooHighException;
    class GradeTooLowException;
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();

    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
};

class Form::GradeTooHighException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Form &form);