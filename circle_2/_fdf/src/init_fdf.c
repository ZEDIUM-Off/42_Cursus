/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:42:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/05 14:17:23 by  mchenava        ###   ########.fr       */
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
	int		i;

	i = 0;
	while (i < fdf->map_height * fdf->map_width)
	{
		col = (float)(i % fdf->map_width);
		row = (float)(i / fdf->map_width);
		fdf->map[i * 3] = -F_SZ_X / 2 + col * F_SZ_X / (fdf->map_width - 1);
		fdf->map[i * 3 + 2] = -F_SZ_Z / 2 + row * F_SZ_Z
			/ (fdf->map_height - 1);
		i++;
	}
}

void	set_indices(t_fdf *fdf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	fdf->indices = ft_calloc(sizeof(unsigned int), (fdf->map_height - 1)
			* (fdf->map_width - 1) * 6);
	while (i < fdf->map_height - 1)
	{
		while (j < fdf->map_width - 1)
		{
			fdf->indices[k] = i * fdf->map_width + j;
			fdf->indices[k + 1] = i * fdf->map_width + j + 1;
			fdf->indices[k + 2] = (i + 1) * fdf->map_width + j;
			fdf->indices[k + 3] = (i + 1) * fdf->map_width + j;
			fdf->indices[k + 4] = i * fdf->map_width + j + 1;
			fdf->indices[k + 5] = (i + 1) * fdf->map_width + j + 1;
			j++;
			k += 6;
		}
		j = 0;
		i++;
	}
}

int	setup_fdf_data(t_fdf *fdf, int argc, char **argv)
{
	int		fd;

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
	t_gl_uint			square;
	t_gl_uint			elements;
	t_gl_vertex_attrib	attr;
	t_draw_elements_settings	sett;

	gl_gen_buffers(&fdf->glx, 1, &square);
	gl_bind_buffer(&fdf->glx, GL_ARRAY_BUFFER, square);
	gl_buffer_data(&fdf->glx, GL_ARRAY_BUFFER, sizeof(fdf->map), fdf->map);
	gl_gen_buffers(&fdf->glx, 1, &elements);
	gl_bind_buffer(&fdf->glx, GL_ELEMENT_ARRAY_BUFFER, elements);
	gl_buffer_data(&fdf->glx, GL_ELEMENT_ARRAY_BUFFER, sizeof(fdf->indices), fdf->indices);
	gl_enable_vertex_attrib_array(&fdf->glx, 0);
	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(&fdf->glx, 0, attr, 0);
	gl_clear_color(&fdf->glx, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
	gl_clear(&fdf->glx, GL_COLOR_BUFFER_BIT);
	sett = (t_draw_elements_settings){(fdf->map_height - 1)
			* (fdf->map_width - 1) * 6, GL_UNSIGNED_INT, 0};
	gl_draw_elements(&fdf->glx, GL_TRIANGLES, &sett);
	return (1);
}
