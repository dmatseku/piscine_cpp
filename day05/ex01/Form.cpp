#include "Form.hpp"
#include <iostream>

Form::Form(std::string name, int min_sign_grade, int min_exec_grade):
_name(name), _min_sign_grade(min_sign_grade), _min_exec_grade(min_exec_grade), _signed(false)
{
    if (min_exec_grade > 150 || min_sign_grade > 150)
        throw Form::GradeTooLowException();
    else if (min_exec_grade < 1 || min_sign_grade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(Form const & src):
_name(src._name), _min_sign_grade(src._min_sign_grade), _min_exec_grade(src._min_exec_grade), _signed(src._signed)
{
    *this = src;
    if (this->_min_exec_grade > 150 || this->_min_sign_grade > 150)
        throw Form::GradeTooLowException();
    else if (this->_min_exec_grade < 1 || this->_min_sign_grade < 1)
        throw Form::GradeTooHighException();
}

Form::~Form()
{
    return;
}

Form&
Form::operator =(Form const & src)
{
    if (this != &src)
        this->_signed = src._signed;
    return (*this);
}

std::ostream&
operator<<(std::ostream & out, Form const & src)
{
    out << "Form:" << std::endl
    << "    Name: " << src.getName() << std::endl
    << "    Minimal sign grade: " << src.getMin_sign_grade() << std::endl
    << "    Minimal execute grade: " << src.getMin_exec_grade() << std::endl
    << "    Is signed: " << (src.getSigned() ? "true" : "false") << std::endl;
    return (out);
}


std::string const
Form::getName() const
{
    return (this->_name);
}

int
Form::getMin_sign_grade() const
{
    return (this->_min_sign_grade);
}

int
Form::getMin_exec_grade() const
{
    return (this->_min_exec_grade);
}

bool
Form::getSigned() const
{
    return (this->_signed);
}


void
Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_min_sign_grade)
        throw Form::GradeTooLowException();
    this->_signed = true;
}









Form::GradeTooHighException::GradeTooHighException()
{
    return;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
    return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
    *this = src;
    return;
}

Form::GradeTooHighException&
Form::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Form::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade is too high");
}

















Form::GradeTooLowException::GradeTooLowException()
{
    return;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
    return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
    *this = src;
    return;
}

Form::GradeTooLowException&
Form::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Form::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade is too low");
}