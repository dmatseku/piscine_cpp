#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    ShrubberyCreationForm	form1("form1");
	RobotomyRequestForm		form2("form2");
	PresidentialPardonForm	form3("form3");

	std::srand(std::time(0));
	try
	{
		Bureaucrat	bob("Bob", 150);
		std::cout << bob;
		bob.signForm(form1);
		bob.signForm(form2);
		bob.signForm(form3);
		bob.executeForm(form1);
		bob.executeForm(form2);
		bob.executeForm(form3);
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;
        std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    try
	{
		Bureaucrat	jack("Jack", 140);
		std::cout << jack;
		jack.signForm(form1);
		jack.signForm(form2);
		jack.signForm(form3);
		jack.executeForm(form1);
		jack.executeForm(form2);
		jack.executeForm(form3);
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;
        std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    try
	{
		Bureaucrat	jule("President", 2);
		std::cout << jule;
		jule.signForm(form1);
		jule.signForm(form2);
		jule.signForm(form3);
		jule.executeForm(form1);
		jule.executeForm(form2);
		jule.executeForm(form3);
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;
        std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}