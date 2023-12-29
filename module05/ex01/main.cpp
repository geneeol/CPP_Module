#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Form form("Form", 1, 1);
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Form form("Form", 2, 1);
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 30);
        Form form("Form", 1, 1);
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}