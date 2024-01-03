#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkForm(executor);
    std::cout << "*drilling noises*\n";
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully.\n";
    else
        std::cout << getTarget() << " robotomization failed.\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {}