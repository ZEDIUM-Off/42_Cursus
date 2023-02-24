/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:29:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 11:01:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

void	up_cam_axii(t_camera *cam)
{
	t_mat4	rot;
	t_mat4	rotx;
	t_mat4	roty;

	roty = rotate_y(cam->yaw);
	rotx = rotate_x(cam->pitch);
	rot = mat4_mul(rotx, roty);
	axii_cam(cam);
	cam->dir = vec4_mul_mat(rot, cam->dir);
	cam->right = vec4_mul_mat(rot, cam->right);
	cam->up = vec4_mul_mat(rot, cam->up);
}

void	up_cam_vec(t_camera *cam)
{
	cam->dir->x = cos(deg_to_rad(cam->yaw)) * cos(deg_to_rad(cam->pitch));
	cam->dir->y = sin(deg_to_rad(cam->pitch));
	cam->dir->z = sin(deg_to_rad(cam->yaw)) * cos(deg_to_rad(cam->pitch));
	cam->dir->w = 1;
	cam->dir = vec4_norm(cam->dir);
	cam->right = vec4_norm(vec4_cross(cam->dir, vec4_init(0, 1, 0, 1)));
	cam->up = vec4_norm(vec4_cross(cam->right, cam->dir));
}

void	up_cam_yaw(t_camera *cam, float angle)
{
	cam->yaw += angle;
}

void	up_cam_pitch(t_camera *cam, float angle)
{
	cam->pitch += angle;
}

void	axii_cam(t_camera *cam)
{
	cam->dir = vec4_init(0, 0, 1, 1);
	cam->right = vec4_init(1, 0, 0, 1);
	cam->up = vec4_init(0, 1, 0, 1);
}
