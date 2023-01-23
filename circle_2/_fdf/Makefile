NAME = fdf
MLX_DIR = ./mlx
BUILD_DIR = build
SRC_DIR = ./src
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = ./includes
PF_DIR = $(SRC_DIR)/ft_printf
LIB_DIR = $(SRC_DIR)/libft

LIB_PF = $(PF_DIR)/libftprintf.a
LIBFT = $(LIB_DIR)/libft.a
MLX = libmlx.dylib

SRC = $(SRC_DIR)/main.c
OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# HEADERS = 

PROG_FLAGS = -L/usr/X11/lib -Lmlx -lXext -lX11 -framework OpenGL -framework AppKit
OBJ_FLAGS = -Wall -Werror -Wextra -I$(MLX_DIR) -I$(INCLUDE_DIR) -I$(PF_DIR) -I$(LIB_DIR)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(LIB_PF) $(MLX)
	$(CC) $(PROG_FLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/utils
	$(CC) $(OBJ_FLAGS) -o $@ -c $<

pf : 
	$(MAKE) -C $(PF_DIR)

lib : 
	$(MAKE) -C $(LIB_DIR)

mlibx :
	$(MAKE) -C $(MLX_DIR) re

$(LIB_PF): pf

$(LIBFT): lib

$(MLX): mlibx

clean : 
	$(RM) $(OBJECTS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PF_DIR) clean
	$(MAKE) -C $(LIB_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(PF_DIR) fclean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

check : 
	norminette $(SRC) $(HEADERS)

re : fclean all