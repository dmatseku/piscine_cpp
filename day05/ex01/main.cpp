#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat  a("bur_1", 30);
    std::cout << a;
    Bureaucrat  b("bur_2", 15);
    std::cout << b;
    Form        f("FORM", 25, 25);
    std::cout << f;
    a.signForm(f);
    std::cout << f;
    b.signForm(f);
    std::cout << f;
    return (0);
}