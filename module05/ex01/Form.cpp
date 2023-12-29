#include "Form.hpp"
#include <iostream>


Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign > Form::LOWEST_GRADE || gradeToExecute > Form::LOWEST_GRADE)
        throw GradeTooLowException();
    if (gradeToSign < Form::HIGHEST_GRADE || gradeToExecute < Form::HIGHEST_GRADE)
        throw GradeTooHighException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form::~Form() {}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high (Form)";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low (Form)";
}

std::ostream &operator<<(std::ostream &out, const Form &Form)
{
    std::cout << Form.getName() << " is " << (Form.getIsSigned() ? "" : "not ")
              << "signed, grade to sign: " << Form.getGradeToSign()
              << ", grade to execute: " << Form.getGradeToExecute() << std::endl;
    return out;
}
