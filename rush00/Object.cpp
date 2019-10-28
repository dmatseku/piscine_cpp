#include	"Object.hpp"

Object::~Object(){}

Object::Object(): f(true){}

Object::Object(Object const & copy)
{
	*this = copy;
}

Object::Object(Point const & position, Point const & speed, const int health): f(true)
{
	this->_position = position;
	this->_speed = speed;
	this->_health = health;
}

Object &			Object::operator=(Object const & o)
{
    if (this != &o)
    {
        this->_position = o._position;
        this->_speed = o._speed;
    }
	return *this;
}

Point const &		Object::getPosition() const
{
	return this->_position;
}

void				Object::setPosition(Point const & p)
{
	char c = this->_position.getChar();
	this->_position = p;
	this->_position.setChar(c);
}

Point const &				Object::move()
{
	this->_position += this->_speed;

	return this->_position;
}


Point const &				Object::move(Point const & p)
{
	this->_position += p;

	return this->_position;
}

int					Object::getHealth() const
{
	return this->_health;
}

void				Object::setHealth(const int health)
{
	this->_health = health;
}

void				Object::drow(const int color)
{
	this->_position.drow(color);
}
