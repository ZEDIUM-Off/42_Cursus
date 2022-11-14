for file in $(find . -type f -name "*.c" -o -name "*.h"); do
	if norminette $file; then 
		echo "norminette passed on $file" 
	else 
		echo "norminette failed on $file - norming $file"
		c_formatter_42 $file 
		norminette $file 
	fi
done 