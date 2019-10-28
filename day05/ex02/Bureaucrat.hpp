#pragma once

#include <string>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string const, int);
        Bureaucrat(Bureaucrat const &);
        ~Bureaucrat();

        Bureaucrat&         operator =(Bureaucrat const &);

        std::string const   getName() const;
        int                 getGrade() const;
        void                increment();
        void                decrement();
        void                signForm(Form&) const;
        void                executeForm(Form const & form);







        class GradeTooHighException: public std::exception
        {
        public:
            GradeTooHighException();
            GradeTooHighException(GradeTooHighException const &);
            ~GradeTooHighException() throw();

            GradeTooHighException&  operator=(GradeTooHighException const &);

            const char*	            what() const throw();
        };








        class GradeTooLowException: public std::exception
        {
        public:
            GradeTooLowException();
            GradeTooLowException(GradeTooLowException const &);
            ~GradeTooLowException() throw();

            GradeTooLowException&   operator=(GradeTooLowException const &);

            const char*	            what() const throw();
        };

};

std::ostream&               operator<<(std::ostream &, Bureaucrat const &);
