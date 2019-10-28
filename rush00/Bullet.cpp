#include	"Bullet.hpp"

Bullet::~Bullet(){}

Bullet::Bullet(){}

Bullet::Bullet(Bullet const & copy)
{
	*this = copy;
}

Bullet::Bullet(Point const & P)
{
	this->_position = P;
}

Bullet::Bullet(Point const & pos, Point const & speed):Object(pos, speed, 1)
{
	this->_position.setChar('-');
	this->_position += speed;
}

Bullet &		Bullet::operator=(Bullet const & s)
{
	if (this != &s)
	{
		this->_position = s._position;
		this->_speed = s._speed;
	}
	return *this;
}

bool		Bullet::collision(Object & o)
{
	if ( this->getPosition() == o.getPosition())
	{
		o.setHealth(o.getHealth() - this->_health);
		this->_health = 0;
		return true;
	}
	return false;
}