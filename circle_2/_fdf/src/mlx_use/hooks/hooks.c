/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 11:35:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include <env3D.h>

t_vec4	*perp_dir(t_camera *cam)
{
	return (vec4_crossp(cam->forward, cam->up));
}

void	cam_move_pos(int key, t_mlx_env **env)
{
	// printf("cam forward: %f, %f, %f \n", (*env)->env3d->cam->forward->x, (*env)->env3d->cam->forward->y, (*env)->env3d->cam->forward->z);
	if (key == XK_w)
		(*env)->env3d->cam->pos = vec4_add((*env)->env3d->cam->pos,
				vec4_scale((*env)->env3d->cam->forward, (*env)->env3d->cam->move_speed));
	if (key == XK_s)
		(*env)->env3d->cam->pos = vec4_sub((*env)->env3d->cam->pos,
				vec4_scale((*env)->env3d->cam->forward, (*env)->env3d->cam->move_speed));
	if (key == XK_a)
		(*env)->env3d->cam->pos = vec4_add((*env)->env3d->cam->pos,
				vec4_scale(perp_dir((*env)->env3d->cam), (*env)->env3d->cam->move_speed));
	if (key == XK_d)
		(*env)->env3d->cam->pos = vec4_sub((*env)->env3d->cam->pos,
				vec4_scale(perp_dir((*env)->env3d->cam), (*env)->env3d->cam->move_speed));
	if (key == XK_q)
		(*env)->env3d->cam->pos = vec4_sub((*env)->env3d->cam->pos,
				vec4_scale((*env)->env3d->cam->up, (*env)->env3d->cam->move_speed));
	if (key == XK_e)
		(*env)->env3d->cam->pos = vec4_add((*env)->env3d->cam->pos,
				vec4_scale((*env)->env3d->cam->up, (*env)->env3d->cam->move_speed));
}

void	cam_move_rot(int key, t_mlx_env **env)
{
	if (key == XK_Up)
		up_cam_pitch((*env)->env3d->cam, (*env)->env3d->cam->rot_speed);
	if (key == XK_Down)
		up_cam_pitch((*env)->env3d->cam, -(*env)->env3d->cam->rot_speed);
	if (key == XK_Left)
		up_cam_yaw((*env)->env3d->cam, -(*env)->env3d->cam->rot_speed);
	if (key == XK_Right)
		up_cam_yaw((*env)->env3d->cam, (*env)->env3d->cam->rot_speed);
}

int	cam_controls(int key, t_mlx_env **env)
{
	cam_move_pos(key, env);
	cam_move_rot(key, env);
	update_img(*env);
	return (0);
}
