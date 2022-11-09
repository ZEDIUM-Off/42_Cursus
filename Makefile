save-all: save-circle0

save-circle0: save-libft

save-libft: 
	git submodule update --init
	cd circle_0 && cp _libft/* libft && cd libft && git add . && git commit -m 'auto save' -a && git push
