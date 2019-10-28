#pragma once
#include "Form.hpp"

class Intern
{
public:
    Intern();
    Intern(Intern const &);
    ~Intern();

    Intern& operator=(Intern const &);
    Form*   makeForm(std::string, std::string);
};