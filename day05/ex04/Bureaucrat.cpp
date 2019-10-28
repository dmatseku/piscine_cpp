#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const name, int grade):
_name(name)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
    return;
}

std::string const
Bureaucrat::getName() const
{
    return (this->_name);
}

int
Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void
Bureaucrat::increment()
{
    if (this->_grade <= 1)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade--;
}

void
Bureaucrat::decrement()
{
    if (this->_grade >= 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade++;
}

void
Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void
Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Form cannot execute because " << e.what() << std::endl;
    }
}

Bureaucrat&
Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this != &src)
        this->_grade = src._grade;
    return (*this);
}

std::ostream&
operator<<(std::ostream & out, Bureaucrat const & src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (out);
}
















Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
    return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
    *this = src;
    return;
}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

















Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
    return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
    *this = src;
    return;
}

Bureaucrat::GradeTooLowException&
Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}