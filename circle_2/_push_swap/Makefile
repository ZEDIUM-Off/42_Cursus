NAME = push_swap

SOURCES = ./push_swap.c ./start.c
STACK_SRC = ./libstack/stack_utils.c

HEADERS = push_swap.h ./libstack/stack.h

CFLAGS = -Wall -Wextra -Werror 
EXTRA_FLAGS = -I . -I ./libstack

all :	$(NAME)

$(NAME) : $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(SOURCES) $(STACK_SRC) -o $@

clean :
	$(RM) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

check : 
	norminette $(SOURCES) $(BONUS_SRC) $(HEADERS)

re : fclean all