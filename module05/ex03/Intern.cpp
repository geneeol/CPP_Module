#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::createRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::string requests[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    const std::string formNames[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};

    AForm *(Intern::*formCreators[3])(const std::string &target) = {
        &Intern::createRobotomyForm, &Intern::createPresidentialForm, &Intern::createShrubberyForm};

    for (int i = 0; i < 3; i++)
    {
        if (requests[i] == formName)
        {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Request isn't valid" << std::endl;
    return NULL;
}