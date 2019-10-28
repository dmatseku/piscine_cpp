#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_point = 8;

Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl; 
    return ;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int src)
{
    std::cout << "Int constructor called" << std::endl;
    this->_number = src << _point;
}

Fixed::Fixed(const float src)
{
    std::cout << "Float constructor called" << std::endl;
    this->_number = std::roundf(src * (1 << _point));
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
    return (this->_number);
}

void
Fixed::setRawBits(int const raw)
{
    this->_number = raw;
}

float
Fixed::toFloat() const
{
    return ((float)(this->_number) / (1 << _point));
}

int
Fixed::toInt() const
{
    return ((int)(this->_number >> _point));
}

std::ostream&
operator<<(std::ostream& out, const Fixed& src)
{
    out << src.toFloat();
    return (out);
}