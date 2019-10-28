#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_point = 8;

Fixed::Fixed(): _number(0)
{
    return ;
}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
}

Fixed::Fixed(const int src)
{
    this->_number = src << _point;
}

Fixed::Fixed(const float src)
{
    this->_number = std::roundf(src * (1 << _point));
}

Fixed::~Fixed()
{
    return ;
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

Fixed&
Fixed::operator=(Fixed const & rhs)
{
    if (this != &rhs)
        this->_number = rhs.getRawBits();
    return (*this);
}

std::ostream&
operator<<(std::ostream& out, const Fixed& src)
{
    out << src.toFloat();
    return (out);
}

Fixed&
Fixed::operator ++()
{
    this->_number += 1;
    return (*this);
}

Fixed&
Fixed::operator --()
{
    this->_number -= 1;
    return (*this);
}

Fixed
Fixed::operator ++(int)
{
    Fixed res(*this);
    this->_number += 1;
    return (res);
}

Fixed
Fixed::operator --(int)
{
    Fixed res(*this);
    this->_number -= 1;
    return (res);
}

Fixed
Fixed::operator  +(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed
Fixed::operator  -(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));

}

Fixed
Fixed::operator  /(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed
Fixed::operator  *(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

bool
Fixed::operator ==(const Fixed& rhs) const
{
    return (this->_number == rhs.getRawBits());
}

bool
Fixed::operator !=(const Fixed& rhs) const
{
    return (this->_number != rhs.getRawBits());
}

bool
Fixed::operator  >(const Fixed& rhs) const
{
    return (this->_number > rhs.getRawBits());
}

bool
Fixed::operator  <(const Fixed& rhs) const
{
    return (this->_number < rhs.getRawBits());
}

bool
Fixed::operator >=(const Fixed& rhs) const
{
    return (this->_number >= rhs.getRawBits());
}

bool
Fixed::operator <=(const Fixed& rhs) const
{
    return (this->_number <= rhs.getRawBits());
}

Fixed&
Fixed::min(Fixed& a, Fixed& b)
{
    if (a <= b)
        return (a);
    return (b);
}

Fixed&
Fixed::max(Fixed& a, Fixed& b)
{
    if (a >= b)
        return (a);
    return (b);
}

const  Fixed&
Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a <= b)
        return (a);
    return (b);
}

const  Fixed&
Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a >= b)
        return (a);
    return (b);
}
