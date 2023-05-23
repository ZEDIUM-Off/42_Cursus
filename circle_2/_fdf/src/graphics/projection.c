/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:13:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/23 11:59:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	isometric_view(t_fdf *fdf, t_mat4	result)

{
	t_mat4	proj;
	t_mat4	view;

	(void)fdf;
	identity_mat4(proj);
	identity_mat4(view);
	identity_mat4(result);
	make_orthographic_matrix(proj,
		(float [2]){-(WIDTH / 2), (WIDTH / 2)}, (float [2]){-(HEIGHT / 2), (HEIGHT / 2)}, (float [2]){0.1, 100.0});
	look_at(view, (t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, (t_vec3){0, 1, 0});
	mult_mat4_mat4(result, proj, view);
}

void	cam_proj(t_fdf *fdf, t_mat4	result)
{
	t_cam	*cam;
	t_mat4	proj;
	t_mat4	view;

	identity_mat4(proj);
	identity_mat4(view);
	identity_mat4(result);
	cam = (t_cam *)&fdf->cam;
	make_perspective_matrix(proj,
		radians(cam->zoom), WIDTH / HEIGHT, (float [2]){0.1, 100.0});
	look_at(view, cam->pos, cam->target, (t_vec3){0, 1, 0});
	mult_mat4_mat4(result, proj, view);
}

void	switch_proj(t_fdf *fdf)
{
	if (fdf->proj_mode == ISO)
	{
		fdf->proj_mode = CAM;
		fdf->uniforms.project = cam_proj;
	}
	else
	{
		fdf->proj_mode = ISO;
		fdf->uniforms.project = isometric_view;
	}
}
