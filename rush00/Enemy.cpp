#include	"Enemy.hpp"

Enemy::~Enemy() {}

Enemy::Enemy() {}

Enemy::Enemy(Enemy const & copy)
{
	*this = copy;
}

Enemy::Enemy(Point const & position, Point const & speed, int health): Ship(position, speed, health) {}

Enemy &				Enemy::operator=(Enemy const & p)
{
    if (this != &p)
    {
        this->_speed = p._speed;
        this->_position = p._position;
        this->_health = p._health;
    }
	return *this;
}
