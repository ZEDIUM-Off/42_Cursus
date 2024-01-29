# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 14:53:52 by  mchenava         #+#    #+#              #
#    Updated: 2023/12/13 14:55:56 by  mchenava        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = main.cpp ClapTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re