/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:39:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 14:49:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib3d.h>

void	cam_move_forward(t_camera *cam, float dist)
{
	t_vec3	*forward;

	forward = get_cam_forward(cam);
	if (cam->move_in_world_plane)
	{
		forward->y = 0;
		vec3_norm(forward);
	}
	forward = vec3_scale(forward, dist);
	cam->pos = vec3_add(cam->pos, forward);
	cam->target = vec3_add(cam->target, forward);
}

void	cam_move_up(t_camera *cam, float dist)
{
	t_vec3	*up;

	up = get_cam_up(cam);
	up = vec3_scale(up, dist);
	cam->pos = vec3_add(cam->pos, up);
	cam->target = vec3_add(cam->target, up);
}

void	cam_move_right(t_camera *cam, float dist)
{
	t_vec3	*right;

	right = get_cam_right(cam);
	if (cam->move_in_world_plane)
	{
		right->y = 0;
		vec3_norm(right);
	}
	right = vec3_scale(right, dist);
	cam->pos = vec3_add(cam->pos, right);
	cam->target = vec3_add(cam->target, right);
}

void	cam_move_to_target(t_camera *cam, float delta)
{
	vec3	*forward;
	float	dist;

	dist = vec3_dist(cam->pos, cam->target) + delta;
	if (dist < 0)
		dist = 0.001f;
	forward = get_cam_forward(cam);
	cam->pos = vec3_add(cam->target, vec3_scale(forward, -dist));
}
