#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form::Form("presidential pardon", 25, 5), _target(target)
{
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
Form::Form("presidential pardon", 25, 5)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return;
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    Form::operator=(src);
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

void
PresidentialPardonForm::exec_function() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}