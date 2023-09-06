#pragma once

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat
{
  private:
    const static int MAX_GRADE = 1;
    const static int MIN_GRADE = 150;
    const std::string name;
    int grade;

  public:
    class GradeTooHighException;
    class GradeTooLowException;
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
};

class GradeTooHighException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);