files = $(find . -type f -name "*.c" -o -name "*.h")

if norminette; then 
	echo "norminette passed" 
else 
	for file in $files; do 
		c_formatter_42 $file 
		norminette $file 
	done 
fi