#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target):
Form::Form("robotomy request", 72, 45), _target(target)
{
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
Form::Form("robotomy request", 72, 45)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return;
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    Form::operator=(src);
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

void
RobotomyRequestForm::exec_function() const
{
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "It’s a failure" << std::endl;
}