/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:03:50 by  mchenava         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/10 17:02:40 by  mchenava        ###   ########.fr       */
=======
/*   Updated: 2023/05/10 10:37:21 by  mchenava        ###   ########.fr       */
>>>>>>> 5c34037078b41bb6b17741d768abaa3a871a4ebd
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	draw_map(t_fdf *fdf)
{
	t_draw_elements_settings	sett;

	fdf->uniforms.project(fdf, fdf->uniforms.mvp_mat);
	sett = (t_draw_elements_settings){fdf->indices_size, GL_UNSIGNED_INT, 0};
	gl_clear(&fdf->glx, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gl_enable(&fdf->glx, GL_DEPTH_TEST);
	gl_polygon_mode(&fdf->glx, GL_BACK, GL_LINE);
	gl_draw_elements(&fdf->glx, GL_TRIANGLES, &sett);
	mlx_put_image_to_window(fdf->mxv.mlx, fdf->mxv.win, fdf->mxv.img, 0, 0);
	// printf("draw map\n");
	return (1);
}

int	render(t_fdf *fdf)
{
	draw_map(fdf);
	// display controls
	return (0);
}
