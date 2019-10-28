#pragma once

#include	"Object.hpp"

class	Bullet : public Object
{
	public:

		~Bullet();
		Bullet();
		Bullet(Bullet const & copy);
		Bullet(Point const & pos);
		Bullet(Point const & pos , Point const & sped);

		Bullet &			operator=(Bullet const & s);
		virtual bool		collision(Object & o);
};