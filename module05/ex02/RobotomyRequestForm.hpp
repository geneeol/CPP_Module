#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  private:
    RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    std::string target;

  public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    virtual ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat &executor) const;
};