#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
    Intern  someRandomIntern;
    Bureaucrat  signer("b1", 10);
    Bureaucrat  executor("b2", 1);
    OfficeBlock block(someRandomIntern, signer, executor);

	std::srand(std::time(0));
    try
    {
        block.doBureaucracy("robotomy request", "bender");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}