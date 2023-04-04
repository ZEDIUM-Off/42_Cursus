/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/04 16:17:29 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	int i;

	if (argc != 2)
	{
		ft_printf(2, "Usage: ./fdf <filename>\n");
		return (0);
	}
	fd = test_file(argv[1]);
	if (fd == -1)
		return (0);
	init_fdf(&fdf);
	if (read_file(fd, &fdf) == -1)
		return (0);
	close(fd);
	// printf("|%d|", fdf.map[99 * 3 - 1]);
	for (i = 0; i < fdf.map_height * fdf.map_width * 3; i++)
	{
		if (i % (fdf.map_width * 3) == 0)
			printf(" \n");
		if (i % 3 == 0)
			printf("|");
		printf("%f ", fdf.map[i]);
	}
	// printf("i = %d", i);
	free(fdf.map);
	return (0);
}
