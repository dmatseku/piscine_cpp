#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>
#include <ostream>

class Fixed
{
private:
    int                     _number;
    static const int        _point;
public:
    Fixed();
    Fixed(Fixed const &);
    Fixed(const int);
    Fixed(const float);
    ~Fixed();

    Fixed&                  operator  =(const Fixed&);
    
    Fixed&                  operator ++();
    Fixed&                  operator --();
    Fixed                   operator ++(int);
    Fixed                   operator --(int);


    Fixed                   operator  +(const Fixed&) const;
    Fixed                   operator  -(const Fixed&) const;
    Fixed                   operator  /(const Fixed&) const;
    Fixed                   operator  *(const Fixed&) const;

    bool                    operator ==(const Fixed&) const;
    bool                    operator !=(const Fixed&) const;
    bool                    operator  >(const Fixed&) const;
    bool                    operator  <(const Fixed&) const;
    bool                    operator >=(const Fixed&) const;
    bool                    operator <=(const Fixed&) const;

    int                     getRawBits() const;
    void                    setRawBits(int const);
    float                   toFloat() const;
    int                     toInt() const;

    static Fixed&           min(Fixed& a, Fixed& b);
    static Fixed&           max(Fixed& a, Fixed& b);
    static const  Fixed&    min(const Fixed& a, const Fixed& b);
    static const  Fixed&    max(const Fixed& a, const Fixed& b);
};

std::ostream&               operator<<(std::ostream&, const Fixed&);

#endif