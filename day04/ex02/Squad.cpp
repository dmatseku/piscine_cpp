#include "Squad.hpp"

Squad::Squad()
{
    this->_count = 0;
}

Squad::Squad(Squad const & src)
{
    this->_count = src._count;

    for (int i = 0; i < this->_count; i++)
        this->_marines[i] = src._marines[i]->clone();
}

Squad::~Squad()
{
    for (int i = 0; i < this->_count; i++)
        delete this->_marines[i];
}

Squad&
Squad::operator =(Squad const & src)
{
    if (this != &src)
    {
        this->_count = src._count;

        for (int i = 0; i < this->_count; i++)
            this->_marines[i] = src._marines[i]->clone();
    }
    return (*this);
}

int Squad::getCount() const
{
    return (this->_count);
}

ISpaceMarine*
Squad::getUnit(int nb) const
{
    if (nb < this->_count && nb >= 0)
        return (this->_marines[nb]);
    return (0);
}

int
Squad::push(ISpaceMarine* elem)
{
    if (!elem || this->_count >= UNIT_MAX)
        return (this->_count);
    for (int i = 0; i < this->_count; i++)
        if (this->_marines[i] == elem)
            return (this->_count);
            
    this->_count++;
    this->_marines[this->_count - 1] = elem;
    return (this->_count);
}