/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/21 15:35:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	*line;
	int		size;

	if (fd < 0)
		return (NULL);
	size = get_line_size(fd);
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	read(fd, line, size);
	line[size] = '\0';
	return (line);
}
#include <stdio.h>
int main(){
		int fd = open("test.txt", O_RDONLY);
		char *line = get_next_line(fd);
		printf("%s", line);
}