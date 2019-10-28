#pragma once

#include	"Ship.hpp"

class	Enemy : public Ship
{
	public:
		~Enemy();
		Enemy();
		Enemy(Enemy const & copy);
		Enemy(Point const & position, Point const & speed, int health);

		Enemy &				operator=(Enemy const & p);
};
