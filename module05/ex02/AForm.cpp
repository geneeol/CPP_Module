#include "AForm.hpp"

AForm::~AForm() {}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high (Form)";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low (Form)";
}
