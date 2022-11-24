/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/24 10:54:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *buff)
{
	char	*tmp_buff;
	int		read_bytes;

	if (!buff)
		buff = ft_calloc(1, sizeof(char));
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buff, '\n'))
	{
		tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp_buff)
			return (NULL);
		read_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buff = ft_strjoin(buff, tmp_buff);
		if (!buff)
			return (NULL);
	}
	if (!buff[0])
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}

char	*next_buff(int fd, char *buff)
{
	int		i;

	i = 0;
	if (!buff)
		return (read_file(fd, buff));
	while (buff[i] && buff[i] != '\n')
		i++;
	buff = ft_substr(buff, i + 1, ft_strlen(buff));
	if (!buff)
		return (NULL);
	return (read_file(fd, buff));
}

char	*new_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff)
		return (NULL);
	i = 0;
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// printf("s_buff: |%s|\n", s_buff);
	s_buff = next_buff(fd, s_buff);
	line = new_line(s_buff);
	// free(s_buff);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("/home/codespace/francinette/tests/get_next_line/fsoares/1char.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("line: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line: |%s|\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("line: |%s|\n", line);
// 	free(line);
// }
