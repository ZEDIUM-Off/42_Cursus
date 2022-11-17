NAME = libftprintf.a

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
SOURCES = ./ft_on_flag_action.c ./ft_printf.c ./ft_parse_flags.c ./ft_putstr_fd.c \
					./ft_putnbr_fd.c ./ft_putchar_fd.c ./ft_intlen.c ./ft_puthex_fd.c \
					./ft_uintlen.c ./ft_putunbr_fd.c ./ft_hexlen.c ./ft_putptr_fd.c \
					./ft_toupper.c ./ft_putnull_fd.c

BONUS_SRC = 

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror 
EXTRA_FLAGS = -c -I .
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