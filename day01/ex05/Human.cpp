#include "Human.hpp"

Human::Human()
{
    return ;
}

Human::~Human()
{
    return ;
}

std::string
Human::identify() const
{
    return (this->_brain.identify());
}

Brain
Human::getBrain()
{
    return(_brain);
}