: save-all

save-all: save-circle0

chekout-all: checkout-libft

save-circle0: save-libft

save-libft:
	@echo "saving libft"
	git submodule update --init
	cd circle_0/libft && git add . && if git commit -m 'auto save' -a; then git push; fi

checkout-libft:
	cd circle_0/libft && git checkout master