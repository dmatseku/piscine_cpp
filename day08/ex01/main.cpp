#include "span.hpp"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    Span sp = Span(10);
    try
    {
        for (int i = 0; i < 20; i++)
            sp.addNumber(std::rand() % 200 - 100);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }

    try
    {
    std::cout << sp;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}