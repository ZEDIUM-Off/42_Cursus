/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:57:16 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/04 16:19:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	test_file(const char *file_name)
{
	int		fd;
	char	*file_name_str;

	file_name_str = ft_strrchr(file_name, '.');
	if (file_name_str == NULL || ft_strnstr(file_name_str, ".fdf", 4) == NULL)
		return (
			ft_printf(2, "fdf: \"%s\" is not a '.fdf' file.\n", file_name), -1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf(2, "fdf: \"%s\" doesn't exist.\n", file_name), -1);
	return (fd);
}

int	parse_line(const char *line, t_fdf *fdf)
{
	char	**splitted_line;
	int		i;
	long	value;
	int		index;

	fdf->map = realloc(fdf->map,
			sizeof(float) * fdf->map_width * (fdf->map_height + 1) * 3);
	splitted_line = ft_split(line, ' ');
	if (splitted_line == NULL)
		return (0);
	i = 0;
	while (splitted_line[i] != NULL && i < fdf->map_width)
	{
		value = ft_atoi(splitted_line[i]);
		if (value == LONG_MAX)
			return (ft_printf(2, "fdf: \"%s\" is not a valid map.\n", line),
				ft_free_tab(splitted_line, fdf->map_width), 0);
		index = fdf->map_height * (fdf->map_width) * 3 + i * 3;
		fdf->map[index] = i;
		fdf->map[index + 1] = fdf->map_height;
		fdf->map[index + 2] = value;
		i++;
	}
	return (ft_free_tab(splitted_line, fdf->map_width), 1);
}

int	read_file(int fd, t_fdf *fdf)
{
	char	*line;

	fdf->map_height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (fdf->map_height == 0)
			fdf->map_width = ft_count_words(line, ' ');
		if (fdf->map_width != ft_count_words(line, ' '))
			return (ft_printf(2, "fdf: \"%s\" is not a valid map.\n", line), -1);
		if (!parse_line(no_nl(line), fdf))
			return (free(line), -1);
		free(line);
		line = get_next_line(fd);
		fdf->map_height++;
	}
	if (fdf->map_height == 0)
		return (ft_printf(2, "fdf: \"%s\" is empty.\n", line), -1);
	return (0);
}
