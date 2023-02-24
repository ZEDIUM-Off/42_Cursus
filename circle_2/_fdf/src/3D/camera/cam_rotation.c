/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:47:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 14:17:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib3d.h>

void	cam_yaw(t_camera *cam, float angle)
{
	t_vec3	*up;
	t_vec3	*target_pos;

	up = get_cam_up(cam);
	target_pos = vec3_sub(cam->target, cam->pos);
	target_pos = vec3_rotate_by_axis(target_pos, up, angle);
	if (cam->rot_around_target)
		cam->pos = vec3_sub(cam->target, target_pos);
	else
		cam->target = vec3_add(cam->pos, target_pos);
}

void	cam_pitch(t_camera *cam, float angle)
{
	t_vec3	*up;
	t_vec3	*target_pos;
	t_vec3	*right;
	float	max_angle_up;
	float	max_angle_down;

	up = get_cam_up(cam);
	target_pos = vec3_sub(cam->target, cam->pos);
	if (cam->lock_view)
	{
		max_angle_up = vec3_angle(up, target_pos) - 0.001f;
		if (angle > max_angle_up)
			angle = max_angle_up;
		max_angle_down = vec3_angle(vec3_neg(up), target_pos) * -1.0f + 0.001f;
		if (angle < max_angle_down)
			angle = max_angle_down;
	}
	right = get_cam_right(cam);
	target_pos = vec3_rotate_by_axis(target_pos, right, angle);
	if (cam->rot_around_target)
		cam->pos = vec3_sub(cam->target, target_pos);
	else
		cam->target = vec3_add(cam->pos, target_pos);
	if (cam->rotate_up)
		cam->up = vec3_rotate_by_axis(cam->up, right, angle);
}

void	cam_roll(t_camera *cam, float angle)
{
	t_vec3	*forward;

	forward = get_cam_forward(cam);
	cam->up = vec3_rotate_by_axis(cam->up, forward, angle);
}
