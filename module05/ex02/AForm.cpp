#include "AForm.hpp"
#include <iostream>

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute)
    : name(name), target(target), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign > AForm::LOWEST_GRADE || gradeToExecute > AForm::LOWEST_GRADE)
        throw GradeTooLowException();
    if (gradeToSign < AForm::HIGHEST_GRADE || gradeToExecute < AForm::HIGHEST_GRADE)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : name(other.name), target(other.target), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
    return name;
}

const std::string &AForm::getTarget() const
{
    return target;
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
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    std::cout << AForm.getName() << " is " << (AForm.getIsSigned() ? "" : "not ")
              << "signed, grade to sign: " << AForm.getGradeToSign()
              << ", grade to execute: " << AForm.getGradeToExecute() << std::endl;
    return out;
}

void AForm::checkForm(const Bureaucrat &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}
