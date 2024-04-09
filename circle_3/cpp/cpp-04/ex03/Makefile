# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:35:29 by mchenava          #+#    #+#              #
#    Updated: 2024/04/09 13:01:17 by mchenava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3


SRC = main.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
