#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type)
{
    this->_name = name;
    this->_type = type;
}

Zombie::Zombie()
{
    this->_name = "";
    this->_type = "";
}

Zombie::~Zombie()
{
    return;
}

void    Zombie::announce()
{
    std::string str;

    str = "<" + this->_name + " (" + this->_type + ")> Braiiiiiiinnnssss...";
    std::cout << str << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
}

void    Zombie::set_type(std::string type)
{
    this->_type = type;
}