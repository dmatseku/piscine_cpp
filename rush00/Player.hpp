#pragma once

#include	"Ship.hpp"

class	Player : public Ship
{
	private:
		int		_score;

		Player();
	public:
		virtual ~Player();

		void	upScore();
		int		getScore() const;
		Player(Player const & copy);
		Player(Point const & position, Point const & speed, int health);

		Player &		operator=(Player const & p);
};
