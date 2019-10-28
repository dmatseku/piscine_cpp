#include "Pony.hpp"

Pony::Pony(std::string name)
{
    this->_age = 0;
    this->_height = 0;
    this->_jump_height = 0;
    this->_name = name;
    this->_speed = 0;
    this->_weight = 0;
}

Pony::~Pony()
{
    return;
}

void        Pony::set_speed(int speed)
{
    this->_speed = speed;
}

void        Pony::set_jump_height(int jump_height)
{
    this->_jump_height = jump_height;
}

void        Pony::set_height(int height)
{
        this->_height = height;
}

void        Pony::set_weight(int weight)
{
    this->_weight = weight;
}

void        Pony::set_name(std::string name)
{
    this->_name = name;
}

void        Pony::set_age(int age)
{
    this->_age = age;
}


int         Pony::get_speed()
{
    return(this->_speed);
}

int         Pony::get_jump_height()
{
    return(this->_jump_height);
}

int         Pony::get_height()
{
    return(this->_height);
}

int         Pony::get_weight()
{
    return(this->_weight);
}

std::string Pony::get_name()
{
    return(this->_name);
}

int         Pony::get_age()
{
    return(this->_age);
}