#pragma once

#include	"Point.hpp"

class	Object
{
	protected:
		Point		_position;
		Point		_speed;
		int			_health;


		Object(Object const & copy);
		Object(Point const & position, Point const & speed, int health);
		Object();

		Object &			operator=(Object const & o);

	public:
		void				setHealth(int health);
		int					getHealth() const;
		virtual ~Object();

		bool				f;

		Point const &				getPosition() const;
		void						setPosition(Point const & p);
		Point const &				move();
		Point const &				move(Point const & p);

		void						drow(int color);

		virtual bool				collision(Object & o) = 0;
};
