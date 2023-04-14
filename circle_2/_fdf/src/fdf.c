/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/14 15:35:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	setup_fdf_data(&fdf, argc, argv);
	for (size_t i = 0; i < fdf.map_size; i++)
	{
		// if (i % 3 == 0)
		// 	printf(" | ");
		if (i % (fdf.map_width * 3) == 0)
			printf("\n ");
		printf("%0.2f, ", fdf.map[i]);
	}
	mlx_loop(fdf.mxv.mlx);
	free(fdf.map);
	return (0);
}
