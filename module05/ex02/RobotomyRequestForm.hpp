#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  private:
    RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    virtual ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat &executor) const;
};