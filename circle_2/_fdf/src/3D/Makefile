NAME = lib3d.a

GEOM_DIR = geometry
MAT_DIR = $(GEOM_DIR)/matrix
VEC_DIR = $(GEOM_DIR)/vectors
VEC2_DIR = $(VEC_DIR)/vector2
VEC3_DIR = $(VEC_DIR)/vector3
VEC4_DIR = $(VEC_DIR)/vector4

MAT_SRC =  $(MAT_DIR)/mat4_methods.c $(MAT_DIR)/mat4_methods2.c
VEC2_SRC = $(VEC2_DIR)/vec2_methods.c $(VEC2_DIR)/vec2_methods2.c $(VEC2_DIR)/vec2_init.c
VEC3_SRC = $(VEC3_DIR)/vec3_methods.c $(VEC3_DIR)/vec3_methods2.c $(VEC3_DIR)/vec3_methods3.c $(VEC3_DIR)/vec3_init.c
VEC4_SRC = $(VEC4_DIR)/vec4_methods.c $(VEC4_DIR)/vec4_methods2.c $(VEC4_DIR)/vec4_methods3.c $(VEC4_DIR)/vec4_init.c
COMP_SRC = compute/cam_op.c compute/cam_op2.c compute/env_op.c compute/matrix_op.c compute/proj_op.c

SRC = $(MAT_SRC) $(VEC2_SRC) $(VEC3_SRC) $(VEC4_SRC) $(COMP_SRC) 
HEADERS = geom.h env3D.h

OBJECTS = $(SRC:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra -I . -fsanitize=address -g3

$(NAME) : $(OBJECTS) 
	ar rc $@ $^
	ranlib $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all