/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:46:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 14:53:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "lib3d.h"

# define CAM_NEAR											0.01f
# define CAM_FAR 											1000.0f
# define CAM_MOVE_SPEED 							0.09f
# define CAM_ROT_SPEED 								0.03f
# define CAM_MOUSE_MOVE_SENSITIVITY 	0.003f
# define CAM_MOUSE_SCROLL_SENSITIVITY	1.5f
# define CAM_ORBIT_SPEED 							0.05f

typedef struct s_camera	t_camera;

struct s_camera
{
	t_vec3	*pos;
	t_vec3	*target;
	t_vec3	*up;
	float	fovy;
	int		proj;
	bool	move_in_world_plane;
	bool	rotate_in_world_plane;
	bool	lock_view;
	bool	rotate_up;
};

typedef enum e_cam_mode	t_cam_mode;

enum e_cam_mode
{
	CUSTOM = 0,
	FREE,
	ORBIT,
	FP,
	TP,
};

typedef enum e_cam_proj	t_cam_proj;

enum e_cam_proj
{
	PERSPECTIVE = 0,
	ORTHOGRAPHIC,
};

/**
 * Camera getters
 * from file camera_getters.c
 */
t_vec3	*get_cam_forward(t_camera *cam);
t_vec3	*get_cam_up(t_camera *cam);
t_vec3	*get_cam_right(t_camera *cam);
t_mat4	get_view_mat(t_camera *cam);
t_mat4	get_proj_mat(t_camera *cam, float aspect);

/**
 * Camera movement gestion
 * from file camera_position.c
 */
void	cam_move_forward(t_camera *cam, float dist);
void	cam_move_up(t_camera *cam, float dist);
void	cam_move_right(t_camera *cam, float dist);
void	cam_move_to_target(t_camera *cam, float delta);

/**
 * Camera rotation gestion
 * from file camera_rotation.c
 */
void	cam_yaw(t_camera *cam, float angle);
void	cam_pitch(t_camera *cam, float angle);
void	cam_roll(t_camera *cam, float angle);

/**
 * Camera update by input
 * from file camera_hooks.c
 */
void	cam_update(t_camera *cam, int mode, int key);

#endif