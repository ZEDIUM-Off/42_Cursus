/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:03:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/17 13:20:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	draw_map(t_fdf *fdf)
{
	t_draw_elements_settings	sett;

	fdf->uniforms.project(fdf, fdf->uniforms.mvp_mat);
	sett = (t_draw_elements_settings){fdf->indices_size, GL_UNSIGNED_INT, 0};
	gl_clear(&fdf->glx, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gl_polygon_mode(&fdf->glx, GL_FRONT_AND_BACK, fdf->draw_mode);
	gl_draw_elements(&fdf->glx, GL_TRIANGLES, &sett);
	mlx_put_image_to_window(fdf->mxv.mlx, fdf->mxv.win, fdf->mxv.img, 0, 0);
	return (1);
}

int	render(t_fdf *fdf)
{
	draw_map(fdf);
	// display controls
	return (0);
}

void	switch_draw(t_fdf *fdf)
{
	if (fdf->draw_mode == GL_LINE)
		fdf->draw_mode = GL_FILL;
	else
		fdf->draw_mode = GL_LINE;
}
