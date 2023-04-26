/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_buffers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:38:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/26 15:40:09 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_map_buffers(t_fdf *fdf)
{
	t_gl_vertex_attrib			attr;

	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = 0};
	gl_gen_buffers(&fdf->glx, 1, &fdf->map_vbo);
	gl_bind_buffer(&fdf->glx, GL_ARRAY_BUFFER, fdf->map_vbo);
	gl_buffer_data(&fdf->glx,
		GL_ARRAY_BUFFER, sizeof(float) * fdf->map_size, fdf->map);
	gl_gen_buffers(&fdf->glx, 1, &fdf->map_ibo);
	gl_bind_buffer(&fdf->glx, GL_ELEMENT_ARRAY_BUFFER, fdf->map_ibo);
	gl_buffer_data(&fdf->glx, GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * fdf->indices_size, fdf->indices);
	gl_enable_vertex_attrib_array(&fdf->glx, 0);
	gl_vertex_attrib_pointer(&fdf->glx, 0, attr, 0);
	printf("Map Buffers Setted\n");
}
