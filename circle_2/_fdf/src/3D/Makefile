NAME = lib3d.a

MAT_SRC =  matrix/mat4_methods.c matrix/mat4_methods2.c
VEC2_SRC = vector2/vec2_methods.c vector2/vec2_methods2.c vector2/vec2_init.c
VEC3_SRC = vector3/vec3_methods.c vector3/vec3_methods2.c vector3/vec3_methods3.c vector3/vec3_init.c

SRC = $(MAT_SRC) $(VEC2_SRC) $(VEC3_SRC) compute.c
HEADERS = geom.h env3D.h

OBJECTS = $(SRC:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra -I .

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