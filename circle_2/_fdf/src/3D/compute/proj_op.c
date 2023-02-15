/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 16:33:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

// t_mat4	ortho_proj(t_camera *cam/*, float w_w, float w_h*/)
// {
// 	t_mat4	res;

// 	res = def_mat();
// 	res[0][0] = cam->near * cam->aspect_ratio;
// 	res[1][1] = cam->near / 2 * cam->near * tanf((cam->h_fov * M_PI / 180) / 2);
// 	res[2][2] = -(cam->far + cam->near) / (cam->far - cam->near);
// 	res[2][3] = -(2 * cam->far * cam->near) / (cam->far - cam->near);
// 	res[3][2] = -1;
// 	res[3][3] = 1;
// 	return (res);
// }

t_mat4	pers_proj(t_camera *cam)
{
	t_mat4	res;
	float	h;
	float	w;

	res = def_mat();
	h = cosf(cam->fov / 2) / sinf(cam->fov / 2);
	w = h * cam->aspect_ratio;
	res[0][0] = w;
	res[1][1] = h;
	res[2][2] = (cam->far + cam->near) / (cam->far - cam->near);
	res[2][3] = 1;
	res[3][2] = - (2.0 * cam->far * cam->near) / (cam->far - cam->near);
	res[3][3] = 1;
	return (res);
}

t_projection	*init_proj(t_camera *cam, float w_w, float w_h)
{
	t_projection	*proj;

	proj = (t_projection *)malloc(sizeof(t_projection));
	proj->proj_matrix = pers_proj(cam);
	proj->view_matrix = def_mat();
	proj->view_matrix[0][0] = w_w / 2;
	proj->view_matrix[1][1] = -(w_h / 2);
	proj->view_matrix[2][2] = 1;
	proj->view_matrix[3][0] = w_w / 2;
	proj->view_matrix[3][1] = w_h / 2;
	proj->view_matrix[3][3] = 1;
	return (proj);
}

t_vec2	*proj_point(t_3d_env *env, t_vec4 *point)
{
	float	x;
	float	y;
	t_vec4	*proj_point;

	proj_point = vec4_mul_mat(cam_mat(env->cam), point);
	// printf("proj_point: %f, %f, %f, %f | \t", proj_point->x, proj_point->y, proj_point->z, proj_point->w);

	proj_point = vec4_mul_mat(env->proj->proj_matrix, proj_point);
	// printf("2proj_point: %f, %f, %f, %f | \n", proj_point->x, proj_point->y, proj_point->z, proj_point->w);
	proj_point->x /= proj_point->w;
	proj_point->y /= proj_point->w;
	proj_point->z /= proj_point->w;
	proj_point->w /= proj_point->w;
	proj_point = vec4_mul_mat(env->proj->view_matrix, proj_point);
	x = proj_point->x;
	y = proj_point->y;
	free(proj_point);
	return (vec2_init(x, y));
}
