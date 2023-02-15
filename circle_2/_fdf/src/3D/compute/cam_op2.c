/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 23:55:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_camera	*cam_init(t_vec4 *pos, float w_w, float w_h)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->pos = pos;
	cam->dir = vec4_init(1, 0, 0, 1);
	cam->right = vec4_init(0, 1, 0, 1);
	cam->up = vec4_init(0, 0, 1, 1);
	cam->fov = M_PI / 3;
	cam->aspect_ratio = w_w / w_h;
	cam->near = 0.1;
	cam->far = 1000;
	cam->move_speed = 0.3;
	cam->rot_speed = 0.025;
	cam->pitch = 0;
	cam->yaw = 0;
	cam->roll = 0;
	cam->cam_mat = cam_mat(cam);
	return (cam);
}

t_mat4	cam_mat(t_camera *cam)
{
	t_mat4	trans;
	t_mat4	rot;

	up_cam_axii(cam);
	trans = cam_trans_mat(cam);
	rot = cam_rot_mat(cam);
	return (mat4_mul(trans, rot));
}

t_mat4	cam_trans_mat(t_camera *cam)
{
	t_mat4	res;

	res = def_mat();
	res[0][0] = 1;
	res[1][1] = 1;
	res[2][2] = 1;
	res[3][3] = 1;
	res[3][0] = -cam->pos->x;
	res[3][1] = -cam->pos->y;
	res[3][2] = -cam->pos->z;
	return (res);
}

t_mat4	cam_rot_mat(t_camera *cam)
{
	t_mat4	res;

	res = def_mat();
	res[0][0] = cam->right->x;
	res[1][0] = cam->right->y;
	res[2][0] = cam->right->z;
	res[0][1] = cam->up->x;
	res[1][1] = cam->up->y;
	res[2][1] = cam->up->z;
	res[0][2] = cam->dir->x;
	res[1][2] = cam->dir->y;
	res[2][2] = cam->dir->z;
	res[3][3] = 1;
	return (res);
}
