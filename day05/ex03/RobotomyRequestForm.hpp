#pragma once

#include "Form.hpp"
#include <string>

class RobotomyRequestForm: public Form
{
private:
    std::string             _target;
    RobotomyRequestForm();
protected:
    void                    exec_function() const;
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &);
    ~RobotomyRequestForm();

    RobotomyRequestForm&    operator=(RobotomyRequestForm const &);
};