#include "Victim.hpp"
#include <iostream>

Victim::Victim():
_name("Victim_Noname")
{
    this->message("Some random victim called " + this->_name + " just popped !");
}

Victim::Victim(std::string name):
_name(name)
{
    this->message("Some random victim called " + this->_name + " just popped !");
}

Victim::Victim(const Victim& src)
{
    *this = src;
    this->message("Some random victim called " + this->_name + " just popped !");
}

Victim::~Victim()
{
    this->message("Victim " + this->_name + " just died for no apparent reason !");
}

void
Victim::message(std::string str)
{
    std::cout << str << std::endl;
}

void
Victim::introduce_message()
{
    std::cout << "I'm " << this->_name << " and I like otters !" << std::endl;
}

void
Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::string
Victim::getName() const
{
    return(this->_name);
}

Victim
&Victim::operator =(const Victim &rhs)
{
    if (this != &rhs)
        this->_name = rhs.getName();
    return (*this);
}

std::ostream&
operator <<(std::ostream& out, const Victim& in)
{
    out << "I'm " << in.getName() << " and I like otters !" << std::endl;
    return (out);
}