#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <exception>

Base*   generate()
{
    int r = std::rand() % 3;

    switch (r)
    {
    case 0:
        std::cout << "Generate: A" << std::endl;
        return new A();
        break;

    case 1:
        std::cout << "Generate: B" << std::endl;
        return new B();
        break;
    
    case 2:
        std::cout << "Generate: C" << std::endl;
        return new C();
        break;
    default:
        break;
    }
    return (nullptr);
}

void identify_from_pointer(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base& p)
{
    Base b;
    try
    {
        b = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception& e)
    {
        try
        {
            b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception& e)
        {
            try
            {
                b = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception& e)
            {
                
            }
        }
    }
}

int main()
{
    Base*   base;

    std::srand(std::time(0));
    std::cout << std::endl << "~~~~~~~POINTER~~~~~~~" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        base = generate();
        std::cout << "Found:    ";
        identify_from_pointer(base);
        std::cout << std::endl;
        delete base;
    }
    std::cout << std::endl << "~~~~~~~REFERENCE~~~~~~~" << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
    {
        base = generate();
        std::cout << "Found:    ";
        identify_from_reference(*base);
        std::cout << std::endl;
        delete base;
    }
    return (0);
}