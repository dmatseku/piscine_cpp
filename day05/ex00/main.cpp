#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("a", 5);
        std::cout << a;
        try
        {
            a.increment();
           std::cout << a;
            a.increment();
           std::cout << a;
            a.increment();
           std::cout << a;
            a.increment();
           std::cout << a;
            a.increment();
           std::cout << a;
            a.increment();
           std::cout << a;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("b", -10);
        std::cout << b;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("c", 210);
        std::cout << c;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}