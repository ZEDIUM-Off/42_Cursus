/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:42:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/12 15:59:12 by  mchenava        ###   ########.fr       */
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
		fdf->map[i * 3] = -F_SZ_X / 2 + col * F_SZ_X
			/ (fdf->map_width - 1);
		fdf->map[i * 3 + 1] = -F_SZ_Z / 2 + row * F_SZ_Z
			/ (fdf->map_height - 1);
		i++;
	}
}

void	set_indices(t_fdf *fdf)
{
	int	i;
	int	offset;

	fdf->indices = malloc(sizeof(unsigned int)
			* (fdf->map_width - 1) * (fdf->map_height - 1) * 6);
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
	i = 0;
	while (i < (fdf->map_width - 1) * (fdf->map_height - 1) * 6)
	{
		if (i % 6 == 0)
			printf("\n");
		// if (i % 6 == 3)
		// 	printf(" | ");
		// if (i % ((fdf->map_width - 1) * 6) == 0)
		// 	printf("\n====================\n"); 
		printf("%d, ", fdf->indices[i]);
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
	gl_buffer_data(&fdf->glx, GL_ARRAY_BUFFER, sizeof(float) * fdf->map_height * fdf->map_width * 3, fdf->map);
	gl_gen_buffers(&fdf->glx, 1, &elements);
	gl_bind_buffer(&fdf->glx, GL_ELEMENT_ARRAY_BUFFER, elements);
	gl_buffer_data(&fdf->glx, GL_ELEMENT_ARRAY_BUFFER, sizeof(fdf->indices), fdf->indices);
	gl_enable_vertex_attrib_array(&fdf->glx, 0);
	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(&fdf->glx, 0, attr, 0);
	gl_clear_color(&fdf->glx, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
	gl_clear(&fdf->glx, GL_COLOR_BUFFER_BIT);
	sett = (t_draw_elements_settings){(fdf->map_width - 1) * (fdf->map_height - 1) * 6, GL_UNSIGNED_INT, 0};
	gl_polygon_mode(&fdf->glx, GL_FRONT_AND_BACK, GL_LINE);
	gl_draw_elements(&fdf->glx, GL_TRIANGLES, &sett);
	mlx_put_image_to_window(fdf->mxv.mlx, fdf->mxv.win, fdf->mxv.img, 0, 0);
	return (1);
}
