NAME = push_swap

SOURCES = ./push_swap.c ./start.c ./error.c
STACK_SRC = ./libstack/stack_utils.c
OP_SRC = ./stack_op/stack_op.c

OBJECTS = $(SOURCES:.c=.o) $(STACK_SRC:.c=.o) $(OP_SRC:.c=.o)
OBJDIR = ./objs

LIB_PF = ft_printf/libftprintf.a
HEADERS = push_swap.h ./libstack/stack.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
EXTRA_FLAGS = -I . -I ./libstack -I ./stack_op -I ./ft_printf

all : $(NAME) lib

$(NAME) : $(OBJECTS) $(LIB_PF)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ -c $<

lib : 
	$(MAKE) -C ./ft_printf

$(LIB_PF) : lib

clean :
	$(RM) $(OBJECTS)
	$(MAKE) -C ./ft_printf clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C ./ft_printf fclean

check : 
	norminette $(SOURCES) $(HEADERS)

re : fclean all