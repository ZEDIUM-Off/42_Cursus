/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/25 14:25:39 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *buff)
{
	char	*tmp_buff;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buff, '\n'))
	{
		tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp_buff)
			return (NULL);
		read_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp_buff);
			return (ft_calloc(1, sizeof(char)));
		}
		buff = ft_strjoin(buff, tmp_buff);
	}
	return (buff);
}

char	*next_buff(char *buff)
{
	int		i;
	char	*next_buff;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	next_buff = ft_substr(buff, i + 1, ft_strlen(buff));
	free(buff);
	if (!next_buff)
		return (NULL);
	return (next_buff);
}

char	*new_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	line = ft_substr(buff, 0, i + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 /*|| read(fd, 0, 0) < 0*/)
		return (NULL);
	s_buff = read_file(fd, s_buff);
	line = new_line(s_buff);
	s_buff = next_buff(s_buff);
	if (!s_buff)
		free(s_buff);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// fd = open("test.txt", O_RDONLY);
// 	fd = open("/Users/mchenava/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("line1: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line2: |%s|\n", line);
// 	free(line);
// 	if (BUFFER_SIZE > 100)
// 	{
// 		char *temp;
// 		do {
// 			temp = get_next_line(fd);
// 			printf("temp: |%s|\n", temp);
// 			free(temp);
// 		} while (temp != NULL);
// 	}
// 	line = get_next_line(fd);
// 	printf("line3: |%s|\n", line);
// 	free(line);
// 	close(fd);
// 	fd = open("/Users/mchenava/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("line4: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line5: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line6: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line7: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line8: |%s|\n", line);
// 	free(line);
// }
