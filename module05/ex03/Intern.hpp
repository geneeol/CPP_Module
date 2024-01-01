#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);

  public:
    Intern();
    virtual ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target);
    AForm *createRobotomyForm(const std::string &target);
    AForm *createPresidentialForm(const std::string &target);
    AForm *createShrubberyForm(const std::string &target);
};