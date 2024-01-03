#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
    PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat &executor) const;
};