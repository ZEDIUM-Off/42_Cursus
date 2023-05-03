NAME = fdf
MLX_OSX_DIR = ./mlx-osx
MLX_LIN_DIR = ./mlx-linux
BUILD_DIR = build
SRC_DIR = ./src
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = ./includes
PF_DIR = ./ft_printf
LIB_DIR = ./libft
GL_DIR = ./42LiteGL
GNL_DIR = ./gnl

WIN_DIR = $(SRC_DIR)/window
GRAPH_DIR = $(SRC_DIR)/graphics
CAM_DIR = $(SRC_DIR)/camera
CTRL_DIR = $(SRC_DIR)/controls

LIB_PF = $(PF_DIR)/libftprintf.a
LIBFT = $(LIB_DIR)/libft.a
MLX = libmlx.dylib
MLX_LIN = $(MLX_LIN_DIR)/libmlx.a
GL = $(GL_DIR)/lite_gl.a


WIN_SRC = $(WIN_DIR)/init_window.c \
					$(WIN_DIR)/set_hooks.c

GRAPH_SRC = $(GRAPH_DIR)/setup_glx.c \
						$(GRAPH_DIR)/set_map_buffers.c \
						$(GRAPH_DIR)/projection.c \
						$(GRAPH_DIR)/shaders.c \
						$(GRAPH_DIR)/draw_map.c \

CAM_SRC = $(CAM_DIR)/init_cam.c \
					$(CAM_DIR)/move_cam.c

CTRL_SRC = $(CTRL_DIR)/mouse_ctrl.c

SRC = $(SRC_DIR)/fdf.c $(SRC_DIR)/read_file.c $(SRC_DIR)/init_fdf.c $(SRC_DIR)/run_app.c $(SRC_DIR)/clean.c
SRC += $(WIN_SRC) $(GRAPH_SRC) $(CAM_SRC) $(CTRL_SRC)
GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c


OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o) #$(GNL:%.c=%.o)
HEADERS = $(SRC_DIR)/fdf.h $(PF_DIR)/ft_printf.h $(LIB_DIR)/libft.h $(GL_DIR)/lite_gl.h

OSX_FLAGS = -Lmlx-osx -framework OpenGL -framework AppKit
LIN_FLAGS = -Lmlx-linux -lXext -lX11 -lm -I$(MLX_LIN_DIR)
OBJ_FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -I$(LIB_DIR) -I$(MLX_LIN_DIR) -I$(INCLUDE_DIR) -I$(PF_DIR) -I$(GL_DIR) -I$(GNL_DIR) -I$(SRC_DIR) -I/usr/X11/include -I$(MLX_OSX_DIR)

all : $(NAME)

$(NAME) : linux

linux: $(OBJECTS) $(LIBFT) $(LIB_PF) $(MLX_LIN) $(GL) $(GNL) 
	$(CC) $(LIN_FLAGS) -fsanitize=address -g3 -o $(NAME) $^

mac: $(OBJECTS) $(LIBFT) $(LIB_PF) $(MLX_LIN) $(GL)
	$(CC) $(OSX_FLAGS) -fsanitize=address -g3 -o $(NAME) $^


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/window
	mkdir -p $(BUILD_DIR)/graphics
	mkdir -p $(BUILD_DIR)/camera
	mkdir -p $(BUILD_DIR)/controls
	$(CC) $(OBJ_FLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(OBJ_FLAGS) -o $@ -c $<

pf : 
	$(MAKE) -C $(PF_DIR)

lib : 
	$(MAKE) -C $(LIB_DIR)

mlibx :
	$(MAKE) -C $(MLX_OSX_DIR)

mlibx_lin :
	$(MAKE) -C $(MLX_LIN_DIR)

gl :
	$(MAKE) -C $(GL_DIR)

$(LIB_PF): pf

$(LIBFT): lib

$(MLX): mlibx

$(MLX_LIN): mlibx_lin

$(GL): gl

clean : 
	$(RM) $(OBJECTS)
	$(MAKE) -C $(MLX_OSX_DIR) clean
	$(MAKE) -C $(MLX_LIN_DIR) clean
	$(MAKE) -C $(PF_DIR) clean
	$(MAKE) -C $(LIB_DIR) clean
	#* $(MAKE) -C $(GL_DIR) clean *#

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(PF_DIR) fclean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_OSX_DIR) fclean
	# $(MAKE) -C $(MLX_LIN_DIR) fclean
	$(MAKE) -C $(GL_DIR) fclean

check : 
	norminette $(SRC) $(HEADERS)

re : fclean all