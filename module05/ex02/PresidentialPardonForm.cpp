#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkForm(executor);
    std::cout << target << " has been pardoned by Zafod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {}