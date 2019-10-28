#pragma once

class		Point
{
	private:
		int		_x;
		int		_y;
		char	_c;

	public:
		~Point();
		Point();
		Point(Point const & copy);
		Point(int x, int y);
		Point(int x, int y, char c);

		Point &			operator=(Point const & p);
		Point &			operator+=(Point const & p);
		bool			operator==(Point const & p) const;

		int				getX() const;
		int				getY() const;
		char			getChar() const;

		void			setX(int x);
		void			setY(int y);
		void			setChar(char c);

		void			drow(int color) const;
};
