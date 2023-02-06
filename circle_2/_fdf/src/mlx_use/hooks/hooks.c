/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/06 16:21:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include <env3D.h>

int cam_controls(int key, t_mlx_env **env)
{
	if (key == XK_w)
		(*env)->env3d->cam->pos = vec4_add((*env)->env3d->cam->pos, vec4_scale((*env)->env3d->cam->forward,(*env)->env3d->cam->move_speed));
	if (key == XK_s)
		(*env)->env3d->cam->pos = vec4_sub((*env)->env3d->cam->pos, vec4_scale((*env)->env3d->cam->forward,(*env)->env3d->cam->move_speed));
	if (key == XK_a)
		(*env)->env3d->cam->pos = vec4_sub((*env)->env3d->cam->pos, vec4_scale((*env)->env3d->cam->right,(*env)->env3d->cam->move_speed));
	if (key == XK_d)
		(*env)->env3d->cam->pos = vec4_add((*env)->env3d->cam->pos, vec4_scale((*env)->env3d->cam->right,(*env)->env3d->cam->move_speed));
	if (key == XK_q)
		(*env)->env3d->cam->pos = vec4_sub((*env)->env3d->cam->pos, vec4_scale((*env)->env3d->cam->up,(*env)->env3d->cam->move_speed));
	if (key == XK_e)
		(*env)->env3d->cam->pos = vec4_add((*env)->env3d->cam->pos, vec4_scale((*env)->env3d->cam->up,(*env)->env3d->cam->move_speed));
	if (key == XK_Up)
		up_cam_pitch((*env)->env3d->cam, (*env)->env3d->cam->rot_speed);
	if (key == XK_Down)
		up_cam_pitch((*env)->env3d->cam, -(*env)->env3d->cam->rot_speed);
	if (key == XK_Left)
		up_cam_yaw((*env)->env3d->cam, -(*env)->env3d->cam->rot_speed);
	if (key == XK_Right)
		up_cam_yaw((*env)->env3d->cam, (*env)->env3d->cam->rot_speed);
	update_img(*env, (*env)->cube);
	return (0);
}

