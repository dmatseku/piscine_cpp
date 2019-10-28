#include "PowerFist.hpp"
#include "AWeapon.hpp"
#include <iostream>

PowerFist::PowerFist():
AWeapon::AWeapon("Power Fist", 8, 50)
{
    return;
}

PowerFist::PowerFist(const PowerFist& src):
AWeapon::AWeapon("Power Fist", 8, 50)
{
    *this = src;
}

PowerFist::~PowerFist()
{
    return;
}

PowerFist&
PowerFist::operator =(const PowerFist &rhs)
{
    if (this != &rhs)
        AWeapon::operator=(rhs);
    return (*this);
}

void
PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}