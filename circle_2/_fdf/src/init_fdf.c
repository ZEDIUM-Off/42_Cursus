/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:42:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/17 12:05:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_fdf(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->indices = NULL;
	fdf->map_width = 0;
	fdf->map_height = 0;
}

void	build_map(t_fdf	*fdf)
{
	float	col;
	float	row;
	size_t	i;

	i = 0;
	while (i < fdf->map_height * fdf->map_width)
	{
		col = (float)(i % fdf->map_width);
		row = (float)(i / fdf->map_width);
		fdf->map[i * 3] = -F_SZ_X / 2 + col * F_SZ_X
			/ (fdf->map_width - 1);
		fdf->map[i * 3 + 2] = -F_SZ_Z / 2 + row * F_SZ_Z
			/ (fdf->map_width - 1);
		i++;
	}
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
	t_draw_elements_settings	sett;

	if (argc != 2)
		return (ft_printf(2, "Usage: ./fdf <filename>.fdf\n"), 1);
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
	struct s_uniform {
		t_mat4	mvp_mat;
	} ud = {
		.mvp_mat = isometric_view(),
	};
	lgl_set_uniform(&fdf->glx, &ud);
	sett = (t_draw_elements_settings){fdf->indices_size, GL_UNSIGNED_INT, 0};
	gl_polygon_mode(&fdf->glx, GL_FRONT_AND_BACK, GL_LINE);
	gl_draw_elements(&fdf->glx, GL_TRIANGLES, &sett);
	mlx_put_image_to_window(fdf->mxv.mlx, fdf->mxv.win, fdf->mxv.img, 0, 0);
	return (1);
}
