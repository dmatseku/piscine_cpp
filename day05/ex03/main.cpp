#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern  someRandomIntern;
    Form*   rrf;
    Form*   err;

	std::srand(std::time(0));
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    err = someRandomIntern.makeForm("asdasd asdasd ", "Error");
    if (rrf)
        delete rrf;
    if (err)
        delete err;
    return (0);
}