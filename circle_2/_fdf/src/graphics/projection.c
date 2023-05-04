/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:13:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:41:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	isometric_view(t_fdf *fdf, t_mat4	view)

{
	(void)fdf;
	identity_mat4(view);
	view[0][0] = 0.7071067811865475;
	view[0][2] = 0.7071067811865475;
	view[1][0] = 0.4082482904638631;
	view[1][1] = 0.8164965809277261;
	view[1][2] = -0.4082482904638631;
	view[2][0] = -0.5773502691896258;
	view[2][1] = 0.5773502691896258;
	view[2][2] = 0.5773502691896258;
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
