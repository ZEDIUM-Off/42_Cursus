DIRS = $(shell find . -type d -name "_*")


: save-all

save-all: save-circle0

checkout-all: checkout-libft
	

save-circle0: save-libft

save-libft:
	@echo "saving libft"
	git submodule update --init
	cd circle_0 && cp _libft/* libft && cd libft && git add . && if git commit -m 'auto save' -a; then git push -f origin HEAD:main; fi

checkout-libft:
	@echo "checking out libft" 
	cd circle_0/libft && git checkout main

fclean_all :
	for i in $(DIRS); do $(MAKE) -C $$i fclean; done

push: fclean_all
	@echo "sending those file to github :"
	@git status -u
	git add . 
	git commit -m 'send $(shell git status -u | grep circle) to github' -a
	git push

# Fichiers sources
SRC_FILES	=	Bureaucrat.cpp AForm.cpp main.cpp \
				ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
				Intern.cpp
