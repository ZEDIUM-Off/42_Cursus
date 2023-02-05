/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/03 11:08:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_projection	*init_proj(t_camera *cam)
{
	t_projection	*proj;
	float					right;
	float         top;

	proj = (t_projection *)malloc(sizeof(t_projection));
	proj->proj_matrix = def_mat();
	right = tan(cam->h_fov / 2);
	top = tan(cam->v_fov / 2);
	proj->proj_matrix[0][0] = 2 / (right - (-right));
	proj->proj_matrix[1][1] = 2 / (top - (-top));
	proj->proj_matrix[2][2] = (cam->far + cam->near) / (cam->far - cam->near);
	proj->proj_matrix[2][3] = 1;
	proj->proj_matrix[3][2] = -2 * cam->far * cam->near / (cam->far - cam->near);
	proj->view_matrix = def_mat();
	proj->view_matrix[0][0] = WIN_WIDTH / 2;
	proj->view_matrix[1][1] = -(WIN_HEIGHT / 2);
	proj->view_matrix[2][2] = 1;
	proj->view_matrix[3][0] = WIN_WIDTH / 2;
	proj->view_matrix[3][1] = WIN_HEIGHT / 2;
	proj->view_matrix[3][3] = 1;
	return (proj);
}


t_vec2	*proj_point(t_3d_env *env, t_vec4 *point)
{
	float		x;
	float		y;
	t_vec4	*proj_point;

	proj_point = vec4_mul_mat(cam_mat(env->cam), point);
	proj_point = vec4_mul_mat(env->proj->proj_matrix, proj_point);
	proj_point->x /= proj_point->w;
	proj_point->y /= proj_point->w;
	proj_point->z /= proj_point->w;
	proj_point->w /= proj_point->w;

	if (proj_point->x > 2 || proj_point->x < -2)
		proj_point->x = 0;
	if (proj_point->y > 2 || proj_point->y < -2)
		proj_point->y = 0;
	if (proj_point->z > 2 || proj_point->z < -2)
		proj_point->z = 0;
	if (proj_point->w > 2 || proj_point->w < -2)
		proj_point->w = 0;
	proj_point = vec4_mul_mat(env->proj->view_matrix, proj_point);
	x = proj_point->x;
	y = proj_point->y;
	free(proj_point);
	return (vec2_init(x, y));
}