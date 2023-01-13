NAME = pipex
BUILD_DIR = build
SRC_DIR = ./src
INCLUDE_DIR = ./includes
PF_DIR = $(SRC_DIR)/ft_printf
LIB_DIR = $(SRC_DIR)/libft

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parsing.c 

OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

HEADERS = $(INCLUDE_DIR)/pipex.h $(INCLUDE_DIR)/utils.h
LIB_PF = $(PF_DIR)/libftprintf.a
LIBFT = $(LIB_DIR)/libft.a

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE_DIR) -I $(PF_DIR) -I $(LIB_DIR) -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(LIB_PF) 
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

pf : 
	$(MAKE) -C $(PF_DIR)

lib : 
	$(MAKE) -C $(LIB_DIR)

$(LIB_PF): pf

$(LIBFT): lib

clean :
	$(RM) $(OBJECTS)
	$(MAKE) -C $(PF_DIR) clean
	$(MAKE) -C $(LIB_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(PF_DIR) fclean
	$(MAKE) -C $(LIB_DIR) fclean

check : 
	norminette $(SRC) $(HEADERS)

re : fclean all