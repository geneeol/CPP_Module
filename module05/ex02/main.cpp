#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{

    std::srand(std::time(0));

    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 50);
    Bureaucrat b4("b4", 100);

    PresidentialPardonForm ppf("ppf");
    RobotomyRequestForm rrf("rrf");
    ShrubberyCreationForm scf("scf");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;

    std::cout << ppf << std::endl;
    std::cout << rrf << std::endl;
    std::cout << scf << std::endl;

    std::cout << ">==== b1 signs forms ====<\n";
    b1.signForm(ppf);
    b1.signForm(rrf);
    b1.signForm(scf);
    std::cout << "\n\n";

    std::cout << ">===== b1 executes forms =====<\n";
    b1.executeForm(ppf);
    b1.executeForm(rrf);
    b1.executeForm(rrf);
    b1.executeForm(rrf);
    b1.executeForm(scf);
    std::cout << "\n\n";

    std::cout << ">==== b2 signs forms ====<\n";
    b2.signForm(ppf);
    b2.signForm(rrf);
    b2.signForm(scf);
    std::cout << "\n\n";

    std::cout << ">===== b2 executes forms =====<\n";
    b2.executeForm(ppf);
    b2.executeForm(rrf);
    b2.executeForm(scf);
    std::cout << "\n\n";

    std::cout << ">==== b3 signs forms ====<\n";
    b3.signForm(ppf);
    b3.signForm(rrf);
    b3.signForm(scf);
    std::cout << "\n\n";

    std::cout << ">===== b3 executes forms =====<\n";
    b3.executeForm(ppf);
    b3.executeForm(rrf);
    b3.executeForm(scf);
    std::cout << "\n\n";

    std::cout << ">==== b4 signs forms ====<\n";
    b4.signForm(ppf);
    b4.signForm(rrf);
    b4.signForm(scf);
    std::cout << "\n\n";

    std::cout << ">===== b4 executes forms =====<\n";
    b4.executeForm(ppf);
    b4.executeForm(rrf);
    b4.executeForm(scf);
    std::cout << "\n\n";

    return (0);
}