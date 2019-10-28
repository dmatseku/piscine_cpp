# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 16:02:27 by dmatseku          #+#    #+#              #
#    Updated: 2019/09/30 15:04:39 by dmatseku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = Data.cpp\
main.cpp\
add_data.cpp\
search.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Ofast -Wall -Wextra -Werror

INC = main.hpp Data.hpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	clang++ $(FLAGS) $(OBJ) -o $@ -I ./

%.o: %.cpp $(INC)
	clang++ $(FLAGS) -c -o $@ $< -I ./

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean format re
