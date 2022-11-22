/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/22 10:45:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *buff)
{
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	read_bytes = 1;
	while (read_bytes > 0)
		read_bytes = read(fd, buff, BUFFER_SIZE);
	buff = ft_strdup(buff);
	return (buff);
}

char	*next_buff(char *buff)
{
	int		i;
	char	*next_buff;

	i = 0;
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
	if (!buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	line = ft_substr(buff, 0, i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!s_buff)
	{
		s_buff = read_file(fd, s_buff);
		tmp_buff = ft_strdup(s_buff);
	}	
	else
		tmp_buff = next_buff(s);
	line = new_line(buff);
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
// 	free (line);
// }
