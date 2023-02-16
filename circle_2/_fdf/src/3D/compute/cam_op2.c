/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/16 12:24:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_camera	*cam_init(t_vec4 *pos, float w_w, float w_h)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->pos = pos;
	cam->dir = vec4_init(1, 0, 0, 1);
	cam->up = vec4_init(0, 1, 0, 1);
	cam->right = vec4_init(0, 1, 0, 1);
	cam->fov = 45;
	cam->aspect_ratio = w_w / w_h;
	cam->near = 0.1;
	cam->far = 1000;
	cam->move_speed = 0.05;
	cam->rot_speed = 1;
	cam->pitch = 0;
	cam->yaw = -90.0;
	cam->roll = 0;
	up_cam_vec(cam);
	return (cam);
}

t_mat4	look_at(t_vec4 *eye, t_vec4 *target, t_vec4 *up)
{
	t_vec4 *zaxis;
	t_vec4 *xaxis;
	t_vec4 *yaxis;
	t_mat4 res;

	zaxis = vec4_norm(vec4_sub(eye, target));
	xaxis = vec4_norm(vec4_crossp(up, zaxis));
	yaxis = vec4_crossp(zaxis, xaxis);
	res = def_mat();
	res[0][0] = xaxis->x;
	res[1][0] = xaxis->y;
	res[2][0] = xaxis->z;
	res[0][1] = yaxis->x;
	res[1][1] = yaxis->y;
	res[2][1] = yaxis->z;
	res[0][2] = zaxis->x;
	res[1][2] = zaxis->y;
	res[2][2] = zaxis->z;
	res[3][0] = -vec4_dotp(xaxis, eye);
	res[3][1] = -vec4_dotp(yaxis, eye);
	res[3][2] = -vec4_dotp(zaxis, eye);
	res[3][3] = 1;
	return (res);
}

t_mat4	cam_mat(t_camera *cam)
{
	t_vec4 *target;

	target = vec4_add(cam->pos, cam->dir);
	return (look_at(cam->pos, target, cam->up));
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
