/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:16 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/23 15:53:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd)
{
	char	*tmp_buff;
	char	*buff;
	int		i;

	tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buff)
		return (NULL);
	buff = ft_calloc(1, sizeof(char));
	while (read(fd, tmp_buff, BUFFER_SIZE) > 0)
	{
		buff = ft_strjoin(buff, tmp_buff);
		i = 0;
		while (tmp_buff[i])
			tmp_buff[i++] = '\0';
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
	while (buff[i] != '\n' && buff[i])
		i++;
	next_buff = ft_substr(buff, i + 1, ft_strlen(buff));
	free(buff);
	if (!next_buff)
		next_buff = NULL;
	if (!next_buff[0])
	{
		free(next_buff);
		return (NULL);
	}
	return (next_buff);
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
// 	char *temp;

// 	fd = open("/home/codespace/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf(" 1. =|%s|=\n\n", line);
// 	line = get_next_line(fd);
// 	printf(" 2. =|%s|=\n\n", line);
// 	temp = get_next_line(fd);
// 	free(temp);
// 	while (temp != NULL)
// 	{
// 		temp = get_next_line(fd);
// 		free(temp);
// 	}
// 	free(line);
//   close(fd);
// 	fd = open("/home/codespace/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf(" 3. =|%s|=\n\n", line);
// 	line = get_next_line(fd);
// 	printf(" 4. =|%s|=\n\n", line);
// 	line = get_next_line(fd);
// 	printf(" 5. =|%s|=\n\n", line);
// 	line = get_next_line(fd);
// 	printf(" 6. =|%s|=\n\n", line);
// 	line = get_next_line(fd);
// 	printf(" 7. =|%s|=\n\n", line);
// 	free (line);
// }
