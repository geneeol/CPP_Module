#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::string requests[3] = {"robotomy request", "presidential pardon",
                                     "shrubbery creation"};
    const std::string formNames[3] = {"RobotomyRequestForm",
                                      "PresidentialPardonForm",
                                      "ShrubberyCreationForm"};

    AForm *(*formCreators[3])(const std::string &target) = {
        createRobotomyForm, createPresidentialForm, createShrubberyForm};

    for (int i = 0; i < 3; i++)
    {
        if (requests[i] == formName)
        {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}