#include "Enemy.hpp"

Enemy::Enemy():
_hp(0), _type("")
{
    return;
}

Enemy::Enemy(const Enemy& src)
{
    *this = src;
    return;
}

Enemy::Enemy(int hp, std::string const & type):
_hp(hp), _type(type)
{
    return;
}

Enemy::~Enemy()
{
    return;
}

Enemy&
Enemy::operator =(const Enemy& srcs)
{
    if (this != &srcs)
    {
        this->_hp = srcs._hp;
        this->_type = srcs._type;
    }
    return(*this);
}

const std::string
Enemy::getType() const
{
    return(this->_type);
}

int
Enemy::getHP() const
{
    return(this->_hp);
}

void
Enemy::takeDamage(int damage)
{
    if (damage > 0 && this->_hp >= damage)
        this->_hp -= damage;
    else if (this->_hp < damage)
        this->_hp = 0;
}