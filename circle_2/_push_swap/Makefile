NAME = push_swap

SOURCES = ./push_swap.c ./start.c ./error.c ./sort.c
STACK_SRC = ./libstack/stack_utils.c
OP_SRC = ./stack_op/stack_op.c ./big_op/get_node.c ./big_op/swap_values.c ./big_op/top.c
SORT_SRC = ./sorting_algo/radix.c ./sorting_algo/merge.c ./sorting_algo/counting.c ./sorting_algo/bucket.c ./sorting_algo/is_sorted.c ./sorting_algo/quick.c 



OBJECTS = $(SOURCES:.c=.o) $(STACK_SRC:.c=.o) $(OP_SRC:.c=.o) $(SORT_SRC:.c=.o)
OBJDIR = ./objs

LIB_PF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
HEADERS = push_swap.h ./libstack/stack.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
EXTRA_FLAGS = -I . -I ./libstack -I ./stack_op -I ./ft_printf -I ./libft -I ./sorting_algo -I ./big_op

all : $(NAME) pf lib

$(NAME) : $(OBJECTS) $(LIB_PF) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $@ -c $<

pf : 
	$(MAKE) -C ./ft_printf

lib : 
	$(MAKE) -C ./libft

$(LIB_PF) : pf

$(LIBFT) : lib

clean :
	$(RM) $(OBJECTS)
	$(MAKE) -C ./ft_printf clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C ./ft_printf fclean

check : 
	norminette $(SOURCES) $(HEADERS)

re : fclean all