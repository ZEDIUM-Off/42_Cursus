FILES = $(shell find . -type f -name "*.c" -o -name "*.h")

: save-all

save-all: save-circle0

save-circle0: save-libft

save-libft: 
	@echo "saving libft"
	git submodule update --init
	cd circle_0 && cp _libft/* libft && cd libft && git checkout master && git add . && if git commit -m 'auto save' -a; then git push; fi

norm: 
	if norminette; then 
		echo "norminette passed"; 
	else
		for file in $(FILES); do
			c_formatter_42 $file
			norminette $file
		done
	fi