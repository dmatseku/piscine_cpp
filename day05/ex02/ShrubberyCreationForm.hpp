#pragma once

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm: public Form
{
private:
    std::string             _target;
    ShrubberyCreationForm();
protected:
    void                    exec_function() const;
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm&    operator=(ShrubberyCreationForm const &);
};