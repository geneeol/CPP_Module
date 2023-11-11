#include "Bureaucrat.hpp"
#include <iostream>

void create_bureaucrat(const std::string &name, int grade)
{
    try
    {
        Bureaucrat bureaucrat(name, grade);
        std::cout << bureaucrat;
    }
    catch (std::exception &e)
    {
        std::cout << "create_bureaucrat: " << e.what() << std::endl;
    }
}

void increment_bureaucrat(const std::string &name, int grade)
{
    Bureaucrat bureaucrat(name, grade);

    try
    {
        bureaucrat.incrementGrade();
        std::cout << bureaucrat;
    }
    catch (std::exception &e)
    {
        std::cout << "Increment: " << e.what() << std::endl;
    }
}

void decrement_bureaucrat(const std::string &name, int grade)
{
    Bureaucrat bureaucrat(name, grade);

    try
    {
        bureaucrat.decrementGrade();
        std::cout << bureaucrat;
    }
    catch (std::exception &e)
    {
        std::cout << "Decrement: " << e.what() << std::endl;
    }
}

int main(void)
{
    create_bureaucrat("Bureaucrat1", 1);
    create_bureaucrat("Bureaucrat2", 150);
    create_bureaucrat("Bureaucrat3", 0);
    create_bureaucrat("Bureaucrat4", 151);
    increment_bureaucrat("Bureaucrat_inc1", 1);
    increment_bureaucrat("Bureaucrat_inc2", 50);
    decrement_bureaucrat("Bureaucrat_dec1", 150);
    decrement_bureaucrat("Bureaucrat_dec2", 50);
    return 0;
}