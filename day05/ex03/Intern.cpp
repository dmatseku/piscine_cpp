#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
    return;
}

Intern::Intern(Intern const & src)
{
    *this = src;
}

Intern::~Intern()
{
    return;
}


Intern&
Intern::operator=(Intern const &src)
{
    (void)src;
    return (*this);
}

Form*
Intern::makeForm(std::string function, std::string target)
{
    Form*   res;

    res = nullptr;

    try
    {
        if (function == "shrubbery creation")
            res = new ShrubberyCreationForm(target);
        else if (function == "robotomy request")
            res = new RobotomyRequestForm(target);
        else if (function == "presidential pardon")
            res = new PresidentialPardonForm(target);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return (nullptr);
    }
    

    if (res != nullptr)
        std::cout << "Intern creates " << res->getName() << std::endl;
    else
        std::cout << "Input function name incorrect" << std::endl;

    return (res);
}