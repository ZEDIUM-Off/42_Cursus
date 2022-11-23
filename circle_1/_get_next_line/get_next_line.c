/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/23 12:01:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd)
{
	int		read_bytes;
	char	*tmp_buff;
	char	*buff;

	tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buff)
		return (NULL);
	buff = ft_strdup("");
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		buff = ft_strjoin(buff, tmp_buff);
	}
	free(tmp_buff);
	if (!buff[0])
	{
		free(buff);
		buff = NULL;
	}
	return (buff);
}

char	*next_buff(char *buff)
{
	int		i;
	char	*next_buff;

	i = 0;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	while (buff[i] != '\n' && buff[i])
		i++;
	next_buff = ft_substr(buff, i + 1, ft_strlen(buff) - i);
	free(buff);
	return (next_buff);
}

char	*new_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	line = ft_substr(buff, 0, i + 1);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (s_buff == NULL)
		s_buff = read_file(fd);
	else
		s_buff = next_buff(s_buff);
	line = new_line(s_buff);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("=|%s|=", line);
// 	line = get_next_line(fd);
// 	printf("=|%s|=", line);
// 	line = get_next_line(fd);
// 	printf("=|%s|=", line);
// 	line = get_next_line(fd);
// 	printf("=|%s|=", line);
// 	line = get_next_line(fd);
// 	printf("=|%s|=", line);
// 	free (line);
// }
