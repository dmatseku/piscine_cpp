#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed
{
private:
    int                 _number;
    static const int    _point;
public:
    Fixed();
    Fixed(Fixed const &);
    ~Fixed();
    Fixed&              operator=(Fixed const &);
    int                 getRawBits() const;
    void                setRawBits(int const);
};
#endif