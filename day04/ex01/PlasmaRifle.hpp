#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP
#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
public:
    PlasmaRifle();
    PlasmaRifle(const PlasmaRifle&);
    ~PlasmaRifle();

    PlasmaRifle&    operator =(const PlasmaRifle &);

    void            attack() const;
};

#endif