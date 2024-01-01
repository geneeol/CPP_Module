#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    checkForm(executor);
    std::ofstream tree(target + "_shrubbery");

    if (tree.is_open())
    {
        tree << "        &&& &&  & &&\n";
        tree << "    && &\\/&\\|& ()|/ @, &&\n";
        tree << "    &\\/(/&/&||/& /_/)_&/_&\n";
        tree << "&() &\\/&|()|/&\\/ '%\" & ()\n";
        tree << "&_&_&&_\\ |& |&&/&__%_/_& &&\n";
        tree << "&&   && & &| &| /& & % ()& /&&\n";
        tree << "  ()&_---()&\\&\\|&&-&&--%---()~\n";
        tree << "    &&     \\|||\n";
        tree << "            |||\n";
        tree << "            |||\n";
        tree << "            |||\n";
        tree << "      , -=-~  .-^- _\n";
        tree.close();
    }
    else
        std::cout << "Error: Could not open file for writing.\n";
}