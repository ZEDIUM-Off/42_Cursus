NAME		=	Bureaucrat

CXX			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

# Fichiers sources
SRC_FILES	=	Bureaucrat.cpp Form.cpp main.cpp

# Fichiers objets
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

# Couleurs pour l'affichage
YELLOW		=	\033[0;33m
GREEN		=	\033[0;32m
RESET		=	\033[0m

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)Compilation de [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] compilé avec succès!$(RESET)"

# Compilation des fichiers objets
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "$(YELLOW)Suppression des fichiers objets...$(RESET)"
	@rm -f $(OBJ_FILES)
	@echo "$(GREEN)Fichiers objets supprimés.$(RESET)"

# Nettoyage complet (fichiers objets et exécutable)
fclean: clean
	@echo "$(YELLOW)Suppression de l'exécutable [$(NAME)]...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Exécutable [$(NAME)] supprimé.$(RESET)"

# Recompilation
re: fclean all

# Déclaration des règles phony
.PHONY: all clean fclean re