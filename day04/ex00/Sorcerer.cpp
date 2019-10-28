#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer():
_name("Noname"), _title("get out of my room")
{
    this->born_message();
}

Sorcerer::Sorcerer(std::string name, std::string title):
_name(name), _title(title)
{
    this->born_message();
}

Sorcerer::Sorcerer(const Sorcerer& src)
{
    *this = src;
    this->born_message();
}

Sorcerer::~Sorcerer()
{
    this->death_message();
}

void
Sorcerer::born_message()
{
    std::cout << this->_name << ", " << this->_title
    << ", is born !" << std::endl;
}


void
Sorcerer::introduce_message()
{
    std::cout << "I am " << this->_name << ", " << this->_title
    << ", and I like ponies !" << std::endl;
}

void
Sorcerer::death_message()
{
    std::cout << this->_name << ", " << this->_title
    << ", is dead. Consequences will never be the same !" << std::endl;
}

void
Sorcerer::polymorph(Victim const &elem) const
{
    elem.getPolymorphed();
}

std::string
Sorcerer::getName() const
{
    return(this->_name);
}

std::string
Sorcerer::getTitle() const
{
    return(this->_title);
}

Sorcerer
&Sorcerer::operator =(const Sorcerer &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_title = rhs.getTitle();
    }
    return (*this);
}

std::ostream&
operator <<(std::ostream& out, const Sorcerer& in)
{
    out << "I am " << in.getName() << ", " << in.getTitle()
    << ", and I like ponies !" << std::endl;
    return (out);
}
