NAME = libftprintf.a

OBJECTS = $(SOURCES:.c=.o)
SOURCES = ./ft_on_flag_action.c ./ft_printf.c ./ft_parse_flags.c ./ft_putstr_fd.c \
					./ft_putnbr_base.c ./ft_putchar_fd.c ft_strlen.c 

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror 
EXTRA_FLAGS = -c -I $(HEADER)
CC = cc

CLEAN = rm -f

all :	$(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $< -o $@

clean :
	$(CLEAN) $(OBJECTS)
	$(CLEAN) $(BONUS_OBJ)

fclean : clean
	$(CLEAN) $(NAME)
	$(CLEAN) $(TEST_PROG)

check : 
	norminette $(SOURCES) $(BONUS_SRC) $(HEADER)

re : fclean all

bonus : $(BONUS_OBJ) $(OBJECTS)
	ar rc $(NAME) $^
	ranlib $(NAME)