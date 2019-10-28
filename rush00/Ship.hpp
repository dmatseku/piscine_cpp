#pragma once

#include	"Object.hpp"
#include	"Bullet.hpp"

class	Ship : public Object
{
	protected:
		Ship();
		Ship(Ship const & copy);
		Ship(Point const & position, Point const & speed, int health);

	public:
		virtual ~Ship();
		Bullet				doShot(Point const & speed);

		Ship &				operator=(Ship const & s);
		virtual bool		collision(Object & o);

};
