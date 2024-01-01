#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
  private:
    ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    std::string target;

  public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat &executor) const;
};