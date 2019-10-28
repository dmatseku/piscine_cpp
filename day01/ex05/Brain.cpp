#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
    std::stringstream   str;
    str << this;
    this->_address = str.str();
    return ;
}
Brain::~Brain()
{
    return ;
}

std::string
Brain::get_name()
{
    return(this->_name);
}

void
Brain::set_name(std::string name)
{
    this->_name = name;
}

std::string
Brain::identify() const
{
    return (this->_address);
}