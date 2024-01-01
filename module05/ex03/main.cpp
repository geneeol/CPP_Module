#include "Intern.hpp"
#include <iostream>

int main(void)
{
    Intern someRandomIntern;
    AForm *rrf;
    AForm *ppf;
    AForm *scf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << "\n>==== Printing forms ====<" << std::endl;
    std::cout << *rrf;
    std::cout << *ppf;
    std::cout << *scf;
    delete rrf;
    delete ppf;
    delete scf;

    std::cout << "\n>==== Testing invalid request ====<" << std::endl;
    AForm *invalid = someRandomIntern.makeForm("invalid request", "Bender");
    if (invalid == NULL)
        std::cout << "Invalid request" << std::endl;
    else
        delete invalid;
    return 0;
}