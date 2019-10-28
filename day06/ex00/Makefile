NAME = convert

SRC = main.cpp Convertor.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -stdlib=libc++ -std=c++98

all: $(NAME)

$(NAME): $(OBJ) Convertor.hpp
	clang++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp Convertor.hpp
	clang++ $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean format re
