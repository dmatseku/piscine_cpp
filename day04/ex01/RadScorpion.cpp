#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy::Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
    return;
}

RadScorpion::RadScorpion(const RadScorpion& src): Enemy::Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
    *this = src;
    return;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
    return;
}

RadScorpion&
RadScorpion::operator =(const RadScorpion& src)
{
    if (this != &src)
        Enemy::operator=(src);
    return (*this);
}