/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:29:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 15:31:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_mat4	look_at(t_vec3 *cam_pos, t_vec3 *cam_dir, t_vec3 *cam_up)
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
}

t_mat4	perspective(float fov, float aspect, float near, float far)
{
	t_mat4	res;
	float	tan_half_fov;

	res = def_mat();
	tan_half_fov = tan(fov / 2);
	res[0][0] = 1 / (aspect * tan_half_fov);
	res[1][1] = 1 / (tan_half_fov);
	res[2][2] = -(far + near) / (far - near);
	res[2][3] = -1;
	res[3][2] = -(2 * far * near) / (far - near);
	return (res);
}
