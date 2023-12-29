#pragma once

class AForm;

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat
{
  private:
    Bureaucrat();
    const static int HIGHEST_GRADE = 1;
    const static int LOWEST_GRADE = 150;
    const std::string name;
    int grade;

  public:
    class GradeTooHighException;
    class GradeTooLowException;
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);
};

class Bureaucrat::GradeTooHighException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
  public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);