/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/12 12:58:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	setup_fdf_data(&fdf, argc, argv);
	printf("map_width: %d, map_height: %d, map_size: %d \n", fdf.map_width,
		fdf.map_height, fdf.map_width * fdf.map_height);
	for (int i = 0; i < fdf.map_height * fdf.map_width * 3; i++)
	{
		if (i % (fdf.map_width * 3) == 0)
			printf(" \n");
		// if (i % 3 == 0)
		// 	printf(" | ");
		printf("%.02f, ", fdf.map[i]);
		// printf ("i: %d \n", i);
	}
	printf("end of map \n");
	mlx_loop(fdf.mxv.mlx);
	free(fdf.map);
	return (0);
}
