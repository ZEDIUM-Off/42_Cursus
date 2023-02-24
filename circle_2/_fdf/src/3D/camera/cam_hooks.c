/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:11:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 14:48:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib3d.h>
#include <X11/keysym.h>

void	set_cam_booleans(t_camera *cam, int mode)
{
	cam->move_in_world_plane = ((mode == FP) || (mode == TP));
	cam->rotate_in_world_plane = ((mode == TP) || (mode == ORBIT));
	cam->lock_view = ((mode == FP) || (mode == TP) || (mode == ORBIT));
	cam->rotate_up = (mode == FREE);
}

void	cam_rot_hooks(t_camera *cam, vec2 *mouse, int key)
{
	vec2	*mouse;

	mouse = get_mouse_delta();
	if (key == XK_Left)
		cam_yaw(cam, -CAM_ROT_SPEED);
	if (key == XK_Right)
		cam_yaw(cam, CAM_ROT_SPEED);
	if (key == XK_Up)
		cam_pitch(cam, CAM_ROT_SPEED);
	if (key == XK_Down)
		cam_pitch(cam, -CAM_ROT_SPEED);
	if (key == XK_q)
		cam_roll(cam, CAM_ROT_SPEED);
	if (key == XK_e)
		cam_roll(cam, -CAM_ROT_SPEED);
	cam_yaw(cam, -mouse->x * CAM_MOUSE_MOVE_SENSITIVITY);
	cam_pitch(cam, -mouse->y * CAM_MOUSE_MOVE_SENSITIVITY);
}

void	cam_move_hooks(t_camera *cam, int key)
{
	if (key == XK_w)
		cam_move_forward(cam, CAM_MOVE_SPEED);
	if (key == XK_s)
		cam_move_forward(cam, -CAM_MOVE_SPEED);
	if (key == XK_a)
		cam_move_right(cam, -CAM_MOVE_SPEED);
	if (key == XK_d)
		cam_move_right(cam, CAM_MOVE_SPEED);
	if (key == XK_space)
		cam_move_up(cam, CAM_MOVE_SPEED);
	if (key == XK_control_L)
		cam_move_up(cam, -CAM_MOVE_SPEED);
}

void	cam_update(t_camera *cam, int mode, int key)
{
	mat4	*rot;
	vec3	*view;

	set_cam_booleans(cam, mode);
	if (mode == ORBIT)
	{
		rot = mat4_rotate(get_cam_up(cam), CAM_ORBIT_SPEED * get_frame_time());
		view = vec3_sub(cam->pos, cam->target);
		view = vec3_transform(view, rot);
		cam->pos = vec3_add(cam->target, view);
	}
	else
	{
		cam_rot_hooks(cam, mouse, key);
		cam_move_hooks(cam, key);
	}
	if ((mode == TP) || (mode == ORBIT))
	{
		cam_move_to_target(cam, -get_mouse_scroll());
		if (key == XK_subtract)
			cam_move_to_target(cam, 2.0f);
		if (key == XK_add)
			cam_move_to_target(cam, -2.0f);
	}
}
