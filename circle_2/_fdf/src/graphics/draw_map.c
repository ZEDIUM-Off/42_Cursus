/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:03:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/27 23:35:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	draw_map(t_fdf *fdf)
{
	t_draw_elements_settings	sett;

	sett = (t_draw_elements_settings){fdf->indices_size, GL_UNSIGNED_INT, 0};
	gl_enable(&fdf->glx, GL_DEPTH_TEST);
	gl_clear(&fdf->glx, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// gl_depth_func(&fdf->glx, GL_GREATER);
	gl_polygon_mode(&fdf->glx, GL_FRONT_AND_BACK, GL_LINE);
	gl_draw_elements(&fdf->glx, GL_TRIANGLES, &sett);
	mlx_put_image_to_window(fdf->mxv.mlx, fdf->mxv.win, fdf->mxv.img, 0, 0);
	printf("map draw finished	");
	return (1);
}
