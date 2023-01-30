/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:41:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 15:16:08 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV3D_H
# define ENV3D_H

# include "geom.h"

typedef struct s_3d_env	t_3d_env;
struct s_3d_env
{
	t_vec3	*world;
	t_mat4	*world_camera;
	float	screen_width;
	float	screen_height;
	float	render_width;
	float	render_height;
};

typedef struct s_camera	t_camera;


t_vec2	*compute_pixel(t_3d_env *env);

t_mat4	translate(t_vec3	*pos);
t_mat4	scale(float scale);
t_mat4	rotate_x(float angle);
t_mat4	rotate_y(float angle);
t_mat4	rotate_z(float angle);

#endif
