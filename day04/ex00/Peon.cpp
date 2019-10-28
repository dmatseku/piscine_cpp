#include "Peon.hpp"
#include <iostream>

Peon::Peon()
{
    this->_name = "Peon_Noname";
    this->message("Zog zog.");
}

Peon::Peon(std::string name): Victim::Victim(name)
{
    this->_name = name;
    this->message("Zog zog.");
}

Peon::Peon(const Peon& src)
{
    *this = src;
    this->message("Zog zog.");
}

Peon::~Peon()
{
    this->message("Bleuark...");
}

Peon
&Peon::operator =(const Peon &rhs)
{
    if (this != &rhs)
        this->_name = rhs.getName();
    return (*this);
}

void
Peon::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}