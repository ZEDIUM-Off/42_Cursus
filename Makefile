: save-all

save-all: save-circle0

checkout-all: checkout-libft
	

save-circle0: save-libft

save-libft:
	@echo "saving libft"
	git submodule update --init
	cd circle_0 && cp _libft/* libft && cd libft && git add . && if git commit -m 'auto save' -a; then git push origin HEAD:master; fi

checkout-libft:
	@echo "checking out libft" 
	cd circle_0/libft && git checkout master