#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    // TODO: 메인에서 시드 초기화
    // std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkForm(executor);
    std::cout << "*drilling noises*\n";
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully.\n";
    else
        std::cout << target << " robotomization failed.\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {}