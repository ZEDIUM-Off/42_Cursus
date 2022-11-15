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
SOURCES = ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c \
					./ft_islower.c ./ft_isprint.c ./ft_isupper.c ./ft_strlen.c \
					./ft_count_words.c ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c \
					./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c \
					./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c \
					./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c \
					./ft_strdup.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c \
					./ft_strlcpy.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c \
					./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c \
					./ft_toupper.c ./ft_sqrt.c

BONUS_SRC = ./ft_lstadd_back_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstclear_bonus.c \
						./ft_lstdelone_bonus.c ./ft_lstiter_bonus.c ./ft_lstlast_bonus.c \
						./ft_lstmap_bonus.c ./ft_lstnew_bonus.c ./ft_lstsize_bonus.c

HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror 
EXTRA_FLAGS = -c -I .
CC = gcc

CLEAN = rm -f

all :	$(LIB_NAME)

$(LIB_NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $< -o $@

clean :
	$(CLEAN) $(OBJECTS)
	$(CLEAN) $(BONUS_OBJ)

fclean : clean
	$(CLEAN) $(LIB_NAME)
	$(CLEAN) $(TEST_PROG)

check : 
	norminette $(SOURCES) $(BONUS_SRC) $(HEADER)

re : fclean all

bonus : $(BONUS_OBJ) $(OBJECTS)
	ar rc $(LIB_NAME) $^
	ranlib $(LIB_NAME)