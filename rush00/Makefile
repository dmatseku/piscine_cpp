SRC =	main.cpp\
		Point.cpp\
		Object.cpp\
		Ship.cpp\
		Bullet.cpp\
		Player.cpp\
		Enemy.cpp\
		List.cpp

OBJ = $(SRC:.cpp=.o)

NAME = ft_retro

FLAGS = -Wall -Wextra -Werror --std=c++98

.PHONY : all clean fclean re sdlfclean

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -o $(NAME) -lncurses $(OBJ)

%.o:%.cpp
	clang++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
