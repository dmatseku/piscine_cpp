NAME = identify

SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror --std=c++98 -stdlib=libc++

all: $(NAME)

$(NAME): $(OBJ) Base.hpp A.hpp B.hpp C.hpp
	clang++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp
	clang++ $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean format re
