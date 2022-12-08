/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/28 11:26:41 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			free(buff);
			return (ft_calloc(1, sizeof(char)));
		}
		buff = ft_strjoin(buff, tmp_buff);
		if (!buff)
			return (NULL);
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
	if (!buff)
		return (NULL);
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
	static char	*s_buff[FD_MAX + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	s_buff[fd] = read_file(fd, s_buff[fd]);
	line = new_line(s_buff[fd]);
	s_buff[fd] = next_buff(s_buff[fd]);
	return (line);
}