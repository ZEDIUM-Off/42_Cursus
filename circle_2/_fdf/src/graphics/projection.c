/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:13:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/02 15:02:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_mat4	isometric_view(t_fdf *fdf)

{
	t_mat4	view;

	(void)fdf;
	view = identity_mat4();
	view[0][0] = 0.7071067811865475;
	view[0][2] = 0.7071067811865475;
	view[1][0] = 0.4082482904638631;
	view[1][1] = 0.8164965809277261;
	view[1][2] = -0.4082482904638631;
	view[2][0] = -0.5773502691896258;
	view[2][1] = 0.5773502691896258;
	view[2][2] = 0.5773502691896258;
	return (view);
}

t_mat4	cam_proj(t_fdf *fdf)
{
	t_cam	*cam;
	t_mat4	proj;
	t_mat4	view;
	t_mat4	result;

	proj = identity_mat4();
	view = identity_mat4();
	result = identity_mat4();
	cam = (t_cam *)&fdf->cam;
	make_perspective_matrix(proj,
		radians(cam->zoom), WIDTH / HEIGHT, new_float2(0.1, 100.0));
	print_mat4(proj, "proj_matrix");
	look_at(view, cam->pos, cam->target, (t_vec3){0, 1, 0});
	print_mat4(view, "view_matrix");
	mult_mat4_mat4(result, proj, view);
	print_mat4(result, "res");
	return (result);
}
