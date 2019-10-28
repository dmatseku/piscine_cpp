NAME = array

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -stdlib=libc++ -std=c++98

all: $(NAME)

$(NAME): $(OBJ) Array.hpp
	clang++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp Array.hpp
	clang++ $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean format re
