/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:56:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/31 14:02:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_projection	*init_proj(t_camera *cam)
{
	t_projection	*proj;

	proj = (t_projection *)malloc(sizeof(t_projection));
	proj->proj_matrix = mat_def();
	proj->proj_matrix[0][0] = 2 / (tan(cam->h_fov / 2) - (-tan(cam->h_fov / 2)));
	proj->proj_matrix[1][1] = 2 / (tan(cam->v_fov / 2) - (-tan(cam->v_fov / 2)));
	proj->proj_matrix[2][2] = (cam->far + cam->near) / (cam->far - cam->near);
	proj->proj_matrix[2][3] = 1;
	proj->proj_matrix[3][2] = (-2 * cam->far * cam->near) / (cam->far - cam->near);
	proj->view_matrix = mat_def();
	proj->view_matrix[0][0] = WIN_WIDTH / 2;
	proj->view_matrix[1][1] = -(WIN_HEIGHT / 2);
	proj->view_matrix[2][2] = 1;
	proj->view_matrix[3][0] = WIN_WIDTH / 2;
	proj->view_matrix[3][1] = WIN_HEIGHT / 2;
	proj->view_matrix[3][3] = 1;
}


t_vec2	proj_point(t_3d_env *env, t_vec3 *point)
{
	float		x;
	float		y;
	t_vec2	res;

	
}