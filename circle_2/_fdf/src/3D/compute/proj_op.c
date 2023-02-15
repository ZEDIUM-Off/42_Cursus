/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/13 12:12:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_mat4	iso_proj(t_camera *cam)
{
	t_mat4	proj;

	proj = def_mat();
	float					right;
	float         top;

	proj = def_mat();
	right = tan(cam->h_fov / 2);
	top = tan(cam->v_fov / 2);
	proj[0][0] = 2 / (right - (-right));
	proj[0][3] = -(right + (-right)) / (right - (-right));
	proj[1][1] = 2 / (top - (-top));
	proj[1][3] = -(top + (-top)) / (top - (-top));
	proj[2][2] = -2/(cam->far -cam->near);
	proj[2][3] = -(cam->far + cam->near) / (cam->far - cam->near);
	proj[3][3] = 1;
	return (proj);
}

t_mat4 persp_proj(t_camera *cam)
{
	t_mat4	proj;
	float					right;
	float         top;

	proj = def_mat();
	right = tan(cam->h_fov / 2);
	top = tan(cam->v_fov / 2);
	proj[0][0] = 2 / (right - (-right));
	proj[1][1] = 2 / (top - (-top));
	proj[2][2] = (cam->far + cam->near) / (cam->far - cam->near);
	proj[2][3] = 1;
	proj[3][2] = -2 * cam->far * cam->near / (cam->far - cam->near);
	return (proj);
}

t_projection	*init_proj(t_camera *cam, float w_w, float w_h)
{
	t_projection	*proj;
	

	proj = (t_projection *)malloc(sizeof(t_projection));
	proj->proj_matrix = iso_proj(cam);
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
	float		x;
	float		y;
	t_vec4	*proj_point;

	proj_point = vec4_mul_mat(cam_mat(env->cam), point);
	
	proj_point = vec4_mul_mat(env->proj->proj_matrix, proj_point);
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