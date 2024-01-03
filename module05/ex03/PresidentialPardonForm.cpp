#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkForm(executor);
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {}