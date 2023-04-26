/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:42:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/26 15:39:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_fdf(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->indices = NULL;
	fdf->map_width = 0;
	fdf->map_height = 0;
	fdf->uniforms.height_max = 0;
	fdf->uniforms.height_min = 0;
}

void	build_map(t_fdf	*fdf)
{
	t_fdf_uniforms	*u;
	float			col;
	float			row;
	size_t			i;
	float			norm_alt;

	i = 0;
	u = &fdf->uniforms;
	while (i < fdf->map_height * fdf->map_width)
	{
		col = (float)(i % fdf->map_width);
		row = (float)(i / fdf->map_width);
		norm_alt = (fdf->map[i * 3 + 1] - u->height_min)
			/ (u->height_max - u->height_min);
		norm_alt = norm_alt - 0.5;
		fdf->map[i * 3] = -0.5 + col * 1 / (fdf->map_width - 1);
		fdf->map[i * 3 + 1] = norm_alt;
		fdf->map[i * 3 + 2] = -0.5 + row * 1 / (fdf->map_width - 1);
		i++;
	}
	printf("Map Builded\n");
}

void	set_indices(t_fdf *fdf)
{
	size_t	i;
	int		offset;

	fdf->indices = malloc(sizeof(unsigned int) * fdf->indices_size);
	i = 0;
	offset = 0;
	while (i < (fdf->map_width - 1) * (fdf->map_height - 1))
	{
		if (i > 0 && i % (fdf->map_width - 1) == 0)
			offset++;
		fdf->indices[i * 6] = i + offset;
		fdf->indices[i * 6 + 1] = i + offset + fdf->map_width;
		fdf->indices[i * 6 + 2] = i + offset + 1;
		fdf->indices[i * 6 + 3] = i + offset + fdf->map_width;
		fdf->indices[i * 6 + 4] = i + offset + 1;
		fdf->indices[i * 6 + 5] = i + offset + fdf->map_width + 1;
		i++;
	}
}

int	setup_fdf_data(t_fdf *fdf, int argc, char **argv)
{
	int							fd;

	if (argc != 2)
		return (ft_printf(2, FDF_USAGE), 1);
	fd = test_file(argv[1]);
	if (fd == -1)
		return (0);
	init_fdf(fdf);
	if (!read_file(fd, fdf))
		return (0);
	build_map(fdf);
	set_indices(fdf);
	init_window(fdf);
	setup_gl_context(fdf);
	set_map_buffers(fdf);
	fdf_shader_init(fdf);
	draw_map(fdf);
	return (1);
}
