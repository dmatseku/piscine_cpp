#include	"Player.hpp"

Player::~Player()
{
	
}

Player::Player(): _score(0)
{

}

Player::Player(Player const & copy): _score(0)
{
	*this = copy;
}

Player::Player(Point const & pos, Point const & spd , const int health): Ship(pos, spd, health), _score(0){}

Player &		Player::operator=(Player const & p)
{
	if (this != &p)
	{
		this->_speed = p._speed;
		this->_position = p._position;
		this->_health = p._health;
		this->_score = p._score;
	}
	return (*this);
}

void		Player::upScore()
{
	this->_score++;
}

int			Player::getScore() const
{
	return (this->_score);
}
