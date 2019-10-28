#include "PlasmaRifle.hpp"
#include "AWeapon.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle():
AWeapon::AWeapon("Plasma Rifle", 5, 21)
{
    return;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle& src):
AWeapon::AWeapon("Plasma Rifle", 5, 21)
{
    *this = src;
}

PlasmaRifle::~PlasmaRifle()
{
    return;
}

PlasmaRifle&
PlasmaRifle::operator =(const PlasmaRifle &rhs)
{
    if (this != &rhs)
        AWeapon::operator=(rhs);
    return (*this);
}

void
PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}