#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
Form::Form("shrubbery creation", 145, 137), _target(target)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
Form::Form("shrubbery creation", 145, 137)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return;
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    Form::operator=(src);
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

void
ShrubberyCreationForm::exec_function() const
{
    std::ofstream file(this->_target + "_shrubbery");

    if (file.is_open())
    {
        file << "                    /\\     " << std::endl
             << "                   /||\\    " << std::endl
             << "                  / || \\   " << std::endl
             << "                    ||     " << std::endl
             << "                           " << std::endl
             << "      /\\                   " << std::endl
             << "     /||\\                  " << std::endl
             << "    / || \\        /\\       " << std::endl
             << "      ||         /||\\      " << std::endl
             << "                / || \\     " << std::endl
             << "                  ||       " << std::endl
             << "                           " << std::endl;
        file.close();
    }
}