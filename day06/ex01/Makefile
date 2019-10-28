NAME = serialization

SRC = main.cpp Serialization.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror --std=c++98 -stdlib=libc++

all: $(NAME)

$(NAME): $(OBJ) Serialization.hpp
	clang++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp Serialization.hpp
	clang++ $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean format re
