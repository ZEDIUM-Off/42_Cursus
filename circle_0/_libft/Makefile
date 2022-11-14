# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:53:10 by mchenava          #+#    #+#              #
#    Updated: 2022/11/09 14:17:08 by mchenava         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a
TEST_PROG = test.out

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
SOURCES = $(shell find . -type f -name 'ft_*.c' -not -name 'ft_*_bonus.c')
BONUS_SRC = $(shell find . -type f -name 'ft_*_bonus.c')
TEST_MAIN = tests.c
HEADER = .

CFLAGS = -Wall -Wextra -Werror 
EXTRA_FLAGS = -c -I $(HEADER)
CC = gcc

CLEAN = rm -f

all :	$(LIB_NAME)

$(LIB_NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o : %.c
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $< -o $@

clean :
	$(CLEAN) $(OBJECTS)
	$(CLEAN) $(BONUS_OBJ)

fclean : clean
	$(CLEAN) $(LIB_NAME)
	$(CLEAN) $(TEST_PROG)

check : 
	norminette $(SOURCES)

test : check re 
	$(CC) $(CFLAGS) $(LIB_NAME) $(TEST_MAIN) -o $(TEST_PROG)
	$(CLEAN) $(OBJECTS)
	./$(TEST_PROG)

re : fclean all

bonus : $(BONUS_OBJ) $(OBJECTS)
	ar rc $(LIB_NAME) $^
	ranlib $(LIB_NAME)