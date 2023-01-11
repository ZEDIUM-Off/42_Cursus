NAME = pipex
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
PF_DIR = ./ft_printf

SRC = $(SRC_DIR)/pipex/pipex.c

OBJECTS = $(BUILD_DIR)/$(SRC:.c=.o)
HEADERS = $(INCLUDE_DIR)/pipex.h $(INCLUDE_DIR)/utils.h
LIB_PF = $(PF_DIR)/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I $(PF_DIR)

pf : 
	$(MAKE) -C $(PF_DIR)

$(LIB_PF) : pf

$(NAME) : $(OBJECTS) $(LIB_PF)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME) pf

clean :
	$(RM) $(OBJECTS)
	$(MAKE) -C $(PF_DIR) clean

fclean :
	$(RM) $(NAME)
	$(MAKE) -C $(PF_DIR) fclean

check : 
	norminette $(SRC) $(HEADERS)

re : fclean all