/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/17 13:34:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

 t_mat4	ortho_proj(t_camera *cam, float w_w, float w_h)
{
	t_mat4	res;

	res = def_mat();
	res[0][0] = 2 / w_w;
	res[1][1] = 2 / w_h;
	res[2][2] = 2 / (cam->far - cam->near);
	res[3][0] = - (w_w / w_h);
	res[3][1] = - (w_h / w_w);
	res[3][2] = - (cam->far + cam->near) / (cam->far - cam->near);
	res[3][3] = 1;
	return (res);
}

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
	proj->proj_matrix = ortho_proj(cam, w_w, w_h);
	proj->view_matrix = def_mat();
	proj->view_matrix[0][0] = w_w / 2;
	proj->view_matrix[1][1] = -(w_h / 2);
	proj->view_matrix[2][2] = 1;
	proj->view_matrix[3][0] = w_w / 2;
	proj->view_matrix[3][1] = w_h / 2;
	proj->view_matrix[3][3] = 1;
	return (proj);
}

t_vec2	*proj_point(t_3d_env *env, t_vec4 *point, float w_w, float w_h)
{
	float	x;
	float	y;
	t_vec4	*proj_point;

	proj_point = vec4_mul_mat(cam_mat(env->cam), point);
	 //printf("proj_point: %f, %f, %f, %f | \t", proj_point->x, proj_point->y, proj_point->z, proj_point->w);

	proj_point = vec4_mul_mat(env->proj->proj_matrix, proj_point);
	 //printf("2proj_point: %f, %f, %f, %f | \n", proj_point->x, proj_point->y, proj_point->z, proj_point->w);
	proj_point->x /= proj_point->w;
	proj_point->y /= proj_point->w;
	proj_point->z /= proj_point->w;
	proj_point->w /= proj_point->w;


	 //printf("3proj_point: %f, %f, %f, %f | \n", proj_point->x, proj_point->y, proj_point->z, proj_point->w);
	proj_point = vec4_scale(proj_point, 0.5);
	x = (proj_point->x + 0.5) * w_w;
	y = (proj_point->y + 0.5) * w_h;
	free(proj_point);
	return (vec2_init(x, y));
}
