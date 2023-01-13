NAME = pipex
BUILD_DIR = build
SRC_DIR = ./src
INCLUDE_DIR = ./includes
PF_DIR = $(SRC_DIR)/ft_printf

SRC = $(SRC_DIR)/parsing.c $(SRC_DIR)/main.c 

OBJECTS = $(BUILD_DIR)/$(shell basename $(SRC:.c=.o))
HEADERS = $(INCLUDE_DIR)/pipex.h $(INCLUDE_DIR)/utils.h
LIB_PF = $(PF_DIR)/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I $(PF_DIR)

all : $(NAME)

pf : 
	$(MAKE) -C $(PF_DIR)

$(LIB_PF) : pf

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJECTS) $(LIB_PF)
	$(CC) $(CFLAGS) -o $@ $^


clean :
	$(RM) $(OBJECTS)
	$(MAKE) -C $(PF_DIR) clean

fclean :
	$(RM) $(NAME)
	$(MAKE) -C $(PF_DIR) fclean

check : 
	norminette $(SRC) $(HEADERS)

re : fclean all