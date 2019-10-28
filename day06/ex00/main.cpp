#include "Convertor.hpp"
#include <iostream>
#include <iomanip>

int main(int ac, char** av)
{
    if (ac != 2)
        return (0);
    Convertor c(av[1]);

    std::cout << "char: ";
    try
    {
        char out = static_cast<char>(c);
        std::cout << '\'' << out << '\'' << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "int: ";
    try
    {
        std::cout << static_cast<int>(c) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "float: " << std::fixed << std::setprecision(1);
    try
    {
        float f = static_cast<float>(c);
        if (f == +1.0f/0.0f)
            std::cout << '+';
        std::cout << f << 'f' << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "double: " << std::fixed << std::setprecision(1);
    try
    {
        double d = static_cast<double>(c);
        if (d == +1.0/0.0)
            std::cout << '+';
        std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}