#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const   _name;
    int const           _min_sign_grade;
    int const           _min_exec_grade;
    bool                _signed;

    Form();
protected:
    virtual void        exec_function() const = 0;
public:
    Form(std::string, int, int);
    Form(Form const &);
    virtual ~Form();

    Form&               operator =(Form const &);

    std::string const   getName() const;
    int                 getMin_sign_grade() const;
    int                 getMin_exec_grade() const;
    bool                getSigned() const;

    void                beSigned(Bureaucrat const &);
    void                execute(Bureaucrat const &) const;











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








    class NotSignedException: public std::exception
    {
    public:
        NotSignedException();
        NotSignedException(NotSignedException const &);
        ~NotSignedException() throw();

        NotSignedException&   operator=(NotSignedException const &);

        const char*	            what() const throw();
    };
};

std::ostream&           operator<<(std::ostream &, Form const &);