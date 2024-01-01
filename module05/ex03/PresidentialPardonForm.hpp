#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  private:
    PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    std::string target;

  public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat &executor) const;
};