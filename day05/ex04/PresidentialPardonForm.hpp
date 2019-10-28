#pragma once

#include "Form.hpp"
#include <string>

class PresidentialPardonForm: public Form
{
private:
    std::string             _target;
    PresidentialPardonForm();
protected:
    void                    exec_function() const;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(PresidentialPardonForm const &);
};