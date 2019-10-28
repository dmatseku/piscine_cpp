#include "Fixed.hpp"
#include <iostream>

const int Fixed::_point = 8;

Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed&
Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_number = rhs.getRawBits();
    return (*this);
}

int
Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_number);
}

void
Fixed::setRawBits(int const raw)
{
    this->_number = raw;
}