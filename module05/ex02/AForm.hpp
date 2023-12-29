#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class AForm
{
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    const static int HIGHEST_GRADE = 1;
    const static int LOWEST_GRADE = 150;

    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

  public:
    class GradeTooHighException;
    class GradeTooLowException;
    virtual ~AForm();

    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;
};

class AForm::GradeTooHighException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const AForm &form);