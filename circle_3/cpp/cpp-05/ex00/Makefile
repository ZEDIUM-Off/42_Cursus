NAME		=	Bureaucrat

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

#directories
OBJ_DIR		=	obj/

SRC_FILES	=	Bureaucrat.cpp main.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re