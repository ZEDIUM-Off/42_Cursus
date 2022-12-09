NAME = push_swap

SOURCES = ./push_swap.c ./start.c ./error.c
STACK_SRC = ./libstack/stack_utils.c

OBJECTS = $(SOURCES:.c=.o) $(STACK_SRC:.c=.o)
OBJDIR = ./objs
HEADERS = push_swap.h ./libstack/stack.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
EXTRA_FLAGS = -I . -I ./libstack

all :	$(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ -c $<

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

check : 
	norminette $(SOURCES) $(HEADERS)

re : fclean all