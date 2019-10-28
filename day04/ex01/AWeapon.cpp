#include "AWeapon.hpp"

AWeapon::AWeapon():
_name(""), _cost(0), _damage(0)
{
    return;
}

AWeapon::AWeapon(const AWeapon& src)
{
    *this = src;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage):
_name(name), _cost(apcost), _damage(damage)
{
    return;
}

AWeapon::~AWeapon()
{
    return;
}

AWeapon&
AWeapon::operator =(const AWeapon &rhs)
{
    if (this != &rhs)
    {
        this->_damage = rhs._damage;
        this->_cost = rhs._cost;
        this->_name = rhs._name;
    }
    return (*this);
}


const std::string
AWeapon::getName() const
{
    return (this->_name);
}

int
AWeapon::getAPCost() const
{
    return (this->_cost);
}

int
AWeapon::getDamage() const
{
    return (this->_damage);
}