/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:29:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/02 12:09:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

/*t_mat4	look_at(t_vec3 *cam_pos, t_vec3 *cam_dir, t_vec3 *cam_up)
{
	t_mat4	res;
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;

	forward = vec3_normalize(cam_dir);
	right = vec3_normalize(vec3_cross(cam_up, &forward));
	up = vec3_cross(&forward, &right);
	res = def_mat();
	res[0][0] = right.x;
	res[1][0] = right.y;
	res[2][0] = right.z;
	res[0][1] = up.x;
	res[1][1] = up.y;
	res[2][1] = up.z;
	res[0][2] = forward.x;
	res[1][2] = forward.y;
	res[2][2] = forward.z;
	res[3][0] = -vec3_dot(&right, cam_pos);
	res[3][1] = -vec3_dot(&up, cam_pos);
	res[3][2] = -vec3_dot(&forward, cam_pos);
	res[3][3] = 1;
	return (res);
}*/

void	up_cam_axii(t_camera *cam)
{
	t_mat4	rot;
	t_mat4	rotx;
	t_mat4	roty;

	roty = rotate_y(cam->yaw);
	rotx = rotate_x(cam->pitch);
	rot = mat4_mul(rotx, roty);
	axii_cam(cam);
	cam->forward = vec4_mul_mat(rot, cam->forward);
	cam->right = vec4_mul_mat(rot, cam->right);
	cam->up = vec4_mul_mat(rot, cam->up);
}

void up_cam_yaw(t_camera *cam, float angle)
{
	cam->yaw += angle;
}

void up_cam_pitch(t_camera *cam, float angle)
{
	cam->pitch += angle;
}

void axii_cam(t_camera *cam)
{
	cam->forward = vec4_init(0, 0, 1, 1);
	cam->right = vec4_init(1, 0, 0, 1);
	cam->up = vec4_init(0, 1, 0, 1);
}
