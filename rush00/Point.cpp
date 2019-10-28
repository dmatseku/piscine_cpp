#include	<ncurses.h>
#include	"Point.hpp"

Point::~Point(){}

Point::Point(){}

Point::Point(Point const & copy)
{
	*this = copy;
}

Point::Point(int x, int y): _x(x), _y(y), _c(' '){}

Point::Point(int x, int y, char c)
	: _x(x)
	, _y(y)
	, _c(c)
{
}

Point &			Point::operator=(Point const & p)
{
	if (this != &p)
	{
		this->_x = p._x;
		this->_y = p._y;
		this->_c = p._c;
	}
	return *this;
}

bool			Point::operator==(Point const & p) const
{
	return this->_x == p._x && this->_y == p._y;
}

Point &			Point::operator+=(Point const & p)
{
	this->_x += p._x;
	this->_y += p._y;

	return *this;
}

int				Point::getX() const
{
	return this->_x;
}

int				Point::getY() const
{
	return this->_y;
}

char			Point::getChar() const
{
	return this->_c;
}

void			Point::setX(const int x)
{
	this->_x = x;
}
void			Point::setY(const int y)
{
	this->_y = y;
}
void			Point::setChar(const char c)
{
	this->_c = c;
}

void			Point::drow(const int color) const
{
	attron(COLOR_PAIR(color));
	refresh();
	mvwprintw(stdscr, this->_y, this->_x, "%c", this->_c);
	attroff(COLOR_PAIR(color));
}
