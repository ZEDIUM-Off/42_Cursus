/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:41:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 16:31:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV3D_H
# define ENV3D_H

# include "geometry/geom.h"
# include "object/object.h"
# include <stdio.h>

typedef struct s_3d_env		t_3d_env;
typedef struct s_camera		t_camera;
typedef struct s_projection	t_projection;

struct s_3d_env
{
	t_camera		*cam;
	t_projection	*proj;
	t_obj			**objs;
};

struct s_camera
{
	t_mat4	cam_mat;
	t_vec4	*pos;
	t_vec4	*dir;
	t_vec4	*up;
	t_vec4	*right;
	t_vec4	*rot;
	float	fov;
	float	near;
	float	far;
	float	aspect_ratio;
	float	pitch;
	float	yaw;
	float	roll;
	float	move_speed;
	float	rot_speed;
};

struct s_projection
{
	t_mat4	proj_matrix;
	t_mat4	view_matrix;
};

t_3d_env		*init_env3D(t_vec4 *cam_pos, float w_w, float w_h);

t_mat4			translate(t_vec3	*pos);
t_mat4			scale(float scale);
t_mat4			rotate_x(float angle);
t_mat4			rotate_y(float angle);
t_mat4			rotate_z(float angle);

t_projection	*init_proj(t_camera *cam, float w_w, float w_h);
t_vec2			*proj_point(t_3d_env *env, t_vec4 *point);

t_camera		*cam_init(t_vec4 *pos, float w_w, float w_h);
t_mat4			cam_mat(t_camera *cam);
t_mat4			cam_trans_mat(t_camera *cam);
t_mat4			cam_rot_mat(t_camera *cam);
void			up_cam_axii(t_camera *cam);
void			up_cam_yaw(t_camera *cam, float angle);
void			up_cam_pitch(t_camera *cam, float angle);
void			axii_cam(t_camera *cam);
t_vec4			*get_cam_dir(t_camera *cam);

#endif
