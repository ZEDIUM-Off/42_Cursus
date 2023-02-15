NAME = fdf
MLX_OSX_DIR = ./mlx-osx
MLX_LIN_DIR = ./mlx-linux
BUILD_DIR = build
SRC_DIR = ./src
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = ./includes
PF_DIR = $(SRC_DIR)/ft_printf
LIB_DIR = $(SRC_DIR)/libft
3D_DIR = $(SRC_DIR)/3D

LIB_PF = $(PF_DIR)/libftprintf.a
LIBFT = $(LIB_DIR)/libft.a
LIB3D = $(3D_DIR)/lib3d.a
MLX = libmlx.dylib
MLX_LIN = $(MLX_LIN_DIR)/libmlx.a

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/mlx_use/display/init_win.c $(SRC_DIR)/mlx_use/display/update_img.c $(SRC_DIR)/mlx_use/hooks/hooks.c $(SRC_DIR)/mlx_use/drawing/draw.c
OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# HEADERS = 

OSX_FLAGS = -Lmlx-osx -framework OpenGL -framework AppKit
LIN_FLAGS = -Lmlx-linux -lXext -lX11 -lm -I$(MLX_LIN_DIR)
OBJ_FLAGS = -Wall -Werror -Wextra -I$(MLX_LIN_DIR) -I$(INCLUDE_DIR) -I$(PF_DIR) -I$(LIB_DIR) -I$(3D_DIR) -I/usr/X11/include -I$(MLX_OSX_DIR)

all : $(NAME)

$(NAME) : linux

linux: $(OBJECTS) $(LIBFT) $(LIB_PF) $(MLX_LIN) $(LIB3D)
	$(CC) $(LIN_FLAGS) -fsanitize=address -g3 -o $(NAME) $^

mac: $(OBJECTS) $(LIBFT) $(LIB_PF) $(MLX) $(LIB3D)
	$(CC) $(OSX_FLAGS) -fsanitize=address -g3 -o $(NAME) $^


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/utils
	$(CC) $(OBJ_FLAGS) -o $@ -c $<

pf : 
	$(MAKE) -C $(PF_DIR)

lib : 
	$(MAKE) -C $(LIB_DIR)

mlibx :
	$(MAKE) -C $(MLX_OSX_DIR)

mlibx_lin :
	$(MAKE) -C $(MLX_LIN_DIR)

3d :
	$(MAKE) -C $(3D_DIR)

$(LIB_PF): pf

$(LIBFT): lib

$(MLX): mlibx

$(MLX_LIN): mlibx_lin

$(LIB3D) : 3d

clean : 
	$(RM) $(OBJECTS)
	$(MAKE) -C $(MLX_OSX_DIR) clean
	#$(MAKE) -C $(MLX_LIN_DIR) clean
	$(MAKE) -C $(PF_DIR) clean
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(3D_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(PF_DIR) fclean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_OSX_DIR) fclean
	# $(MAKE) -C $(MLX_LIN_DIR) fclean
	$(MAKE) -C $(3D_DIR) fclean

check : 
	norminette $(SRC) $(HEADERS)

re : fclean all