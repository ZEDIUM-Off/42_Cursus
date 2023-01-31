/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:41:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/31 14:02:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV3D_H
# define ENV3D_H

# include "geom.h"

#	define WIN_WIDTH 512
#	define WIN_HEIGHT 512


typedef struct s_3d_env	t_3d_env;
struct s_3d_env
{
	t_camera	*cam;
	t_projection	*proj;
	t_obj		*obj;
};

typedef struct s_camera	t_camera;
struct s_camera
{
	t_vec3	*pos;
	t_vec3	*rot;
	t_vec3	*forward;
	t_vec3	*up;
	t_vec3	*right;
	float	h_fov;
	float	v_fov;
	float	near;
	float	far;
	float	aspect_ratio;
	float	pitch;
	float	yaw;
	float	roll;
	float	move_speed;
	float	rot_speed;
};

typedef struct s_projection	t_projection;
struct s_projection
{
	t_mat4	*proj_matrix;
	t_mat4  *view_matrix;
};

t_vec2	*compute_pixel(t_3d_env *env);

t_mat4	translate(t_vec3	*pos);
t_mat4	scale(float scale);
t_mat4	rotate_x(float angle);
t_mat4	rotate_y(float angle);
t_mat4	rotate_z(float angle);

t_projection	*init_proj(t_camera *cam);

t_camera	*cam_init(t_vec3 *pos);
t_mat4	cam_mat(t_cam *cam);
t_mat4	cam_trans_mat(t_cam *cam);
t_mat4	cam_rot_mat(t_cam *cam);
void	up_cam_axii(t_camera *cam);
void	up_cam_yaw(t_camera *cam, float angle);
void	up_cam_pitch(t_camera *cam, float angle);
void	axii_cam(t_camera *cam);
#endif
