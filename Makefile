: save-all

save-all: save-circle0
	git submodule update --init

save-circle0: save-libft

save-libft: 
	echo "saving libft"
	cd circle_0 && cp _libft/* libft && cd libft && git add . && git commit -m 'auto save' -a && git push
