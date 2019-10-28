#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>
#include <ostream>

class Fixed
{
private:
    int                 _number;
    static const int    _point;
public:
    Fixed();
    Fixed(Fixed const &);
    Fixed(const int);
    Fixed(const float);
    ~Fixed();

    float               toFloat() const;
    int                 toInt() const;

    Fixed&              operator=(Fixed const &);

    int                 getRawBits() const;
    void                setRawBits(int const);
};

std::ostream&           operator<<(std::ostream&, const Fixed&);

#endif