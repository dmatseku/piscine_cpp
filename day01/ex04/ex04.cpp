#include <iostream>

int main()
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    pstr = &str;
    std::string&    rstr = str;

    std::cout
    << "Variable: " << str << std::endl
    << "Pointer: " << *pstr << std::endl
    << "Reference: " << rstr << std::endl;
    return (0);
}