if norminette; then 
	echo "norminette passed" 
else 
	for file in $(find . -type f -name "*.c" -o -name "*.h"); do
		echo "norminette failed on $file - norming $file"
		c_formatter_42 $file 
		norminette $file 
	done 
fi