#include <ncurses.h>
#include <sys/time.h>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "List.hpp"
#include <fstream>
#include <string>
#include <unistd.h>

int					gl_x;
int					gl_y;
int					gl_x1;
int					gl_y1;
int					cycle = 10;

List				b;
List				e;

void	drow_point(Point const &p, int color)
{
	attron(COLOR_PAIR(color));
	mvwprintw(stdscr, p.getY(), p.getX(), "%c", p.getChar());
	attroff(COLOR_PAIR(color));
}

void	draw_borders(WINDOW *screen)
{
	int		x, y;
	getmaxyx(screen, y, x);
    
	std::string const str(x, '-');
    mvwprintw(screen, 0, 0, str.c_str());
    mvwprintw(screen, y - 1, 0, str.c_str());
}

void	change_borders(WINDOW *field, WINDOW *score, int *w, int *z, int score_size)
{
	gl_x = gl_x1;
	gl_y = gl_y1;

	wresize(field, gl_y1 - score_size, gl_x1);
	wresize(score, score_size, gl_x1);
	mvwin(score, gl_y1 - score_size, 0);

	wclear(stdscr);
	wclear(field);
	wclear(score);

	draw_borders(field);
	draw_borders(score);
	*z = (gl_y - score_size - 1) / 2;
	*w = 1;
}


void	change_user_pos(int input, int score_size, Player &user)
{
	Point p(user.getPosition());

	if(input == KEY_RIGHT)
	{
		drow_point(p, 1);
		if ((gl_x - 3) > p.getX())
			p+= Point(1, 0);
	}
	else if(input == KEY_LEFT)
	{
		drow_point(p, 1);
		if (p.getX() > 1)
			p+= Point(-1, 0);
	}
	else if(input == KEY_UP)
	{
		drow_point(p, 1);
		if (p.getY() > 1)
			p+= Point(0, -1);
	}
	else if(input == KEY_DOWN)
	{
		drow_point(p, 1);
		if ((gl_y - score_size - 2) > p.getY())
			p+= Point(0, 1);
	}
	else if(input == ' ')
	{
		b.push(new Bullet(user.getPosition(), Point(1 , 0)));
		drow_point(((Bullet *)b[b.size() - 1])->getPosition(), 6);
	}
	user.setPosition(p);
}

void	init_win()
{
	srand(time(NULL));
	initscr();
	noecho();
	cbreak();
	timeout(0);
	curs_set(0);
	start_color();
	keypad(stdscr, true);

	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_YELLOW);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

void	init_star(Bullet *bul)
{
	for (int i = 0; i < 100; ++i)
	{
		bul[i] = Bullet(Point(std::rand() % (gl_x - 1), std::rand() % (gl_y - 5) + 1, '.'));
	}
}

void drow_objects(List& objects, int color)
{
	for (int i = 0; i < objects.size(); i++)
	{
		Object* const object = static_cast<Object*>(objects[i]);
		if (object->f)
		{
			drow_point(object->getPosition(), color);
		}
	}
}

void		drow_stars(int i, Bullet *bul, Point &p, Point &pStart)
{
	if (i % 20 != 0)
	{
		return;
	}

	for (int n = 0; n < 100; ++n)
	{
		Bullet& bullet = bul[n];
		Point const& bulletPosition = bullet.getPosition();
		
		drow_point(bulletPosition, 1);
		if (bulletPosition.getX() == 0)
		{
			pStart.setX(gl_x);
			pStart.setY(std::rand() % (gl_y - 5) + 1);
			bullet.setPosition(pStart);
		}
		bullet.move(p);
		drow_point(bullet.getPosition(), 6);
	}
}

void		drow_enemy(int i)
{
	static int		a = 5;

	if (i % 100 == 0 && a > 1)
	{
		a--;
	}
	e.push(new Enemy(Point(gl_x, std::rand() % (gl_y - 5) + 1, '#'), Point(-1, 0), 15));

	int const enemy_color = 4;
	drow_objects(e, enemy_color);
}

void		drow_bullet()
{
	int const bullet_color = 2;
	drow_objects(b, bullet_color);
}



bool handel_collision(Object* obl, List& list)
{
	for (int j = 0; j < list.size(); j++)
	{
		Object* const enemy = static_cast<Object*>(list[j]);
		if (obl->f && enemy->f && obl->collision(*enemy))
		{
			list.erase(j);
			return true;
		}
	}

	return false;
}


int		check_collision(Player &user)
{
	for (int i = 0; i < b.size(); i++)
	{
		Object* const bullet = static_cast<Object*>(b[i]);
		
		if (bullet->f)
		{
			bullet->move();
			if (handel_collision(bullet, e))
			{
				b.erase(i);
				i--;
				user.upScore();
			}
		}
	}

	for (int i = 0; i < e.size(); i++)
	{
		Object* const enemy = static_cast<Object*>(e[i]);
		
		if (enemy->f)
		{
			enemy->move();
			if (handel_collision(enemy, b))
			{
				e.erase(i);
				i--;
				user.upScore();
			}
		}
	}

	for (int i = 0; i < e.size(); i++)
	{
		Object* const enemy = static_cast<Enemy*>(e[i]); 
		if (enemy->f && user.collision(*enemy))
		{
			endwin();
			return 0;
		}
	}
	return 1;
}

void    write_hat(int score)
{
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "                 GAME OVER!                  " << std::endl;
    std::cout << "                 Level: " << score / 10 << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

void    draw_time(struct timeval const *const tv1, struct timeval *const tv2,
        WINDOW* score, const int user_score, const int game_cycle)
{

    gettimeofday(tv2, NULL);

	double const usec = static_cast<double>(tv2->tv_usec - tv1->tv_usec);
	double const sec = static_cast<double>(tv2->tv_sec - tv1->tv_sec);

    mvwprintw(score, 1, 1, "Time: %f", usec / 1000000 + sec);
    mvwprintw(score, 1, 20, "Score: %d", user_score);
    mvwprintw(score, 1, 35, "Level: %d", user_score / 10);
    mvwprintw(score, 1, 50, "Cycle: %d", game_cycle);
}

int main()
{
	struct timeval  tv1, tv2;


	init_win();
	int			score_size = 3;
	int			i = 0;
	getmaxyx(stdscr, gl_y, gl_x);
	int			z = (gl_y - score_size - 1) / 2;
	int			w = 1;
	int			input = getch();

	WINDOW *field = newwin(gl_y - score_size, gl_x, 0, 0);
	WINDOW *score = newwin(score_size, gl_x, gl_y - score_size, 0);
	draw_borders(field);
	draw_borders(score);

	Player		user(Point(w, z, '>'), Point(0, 0, 0), 100);
	Bullet		bul[100];
	init_star(bul);
	Point p(-1, 0);
	Point pStart(gl_x, 0);
	while(input != 27 && (++i))
	{
		gettimeofday(&tv1, NULL);
		input = getch();
		change_user_pos(input, score_size, user);
		
		drow_stars(i, bul, p, pStart);
		
		drow_objects(e, 1);
		drow_objects(b, 1);

		getmaxyx(stdscr, gl_y1, gl_x1);
		if (gl_y1 != gl_y || gl_x1 != gl_x)
			change_borders(field, score, &w, &z, score_size);
		
		if(check_collision(user) == 0)
			break ;
		
		drow_bullet();
		drow_enemy(i);
		
		drow_point(user.getPosition(), 5);
		wrefresh(field);
		wrefresh(score);
		
		b.check_out_screen(gl_x1);
        e.check_out_screen(gl_x1);
		
		if ((i + 1) % 500 == 0)
			cycle += cycle / 4;
		usleep(200000 / cycle);
		draw_time(&tv1, &tv2, score, user.getScore(), i);
	}
	endwin();
	write_hat(user.getScore());
	system("leaks -q ft_retro");
}
