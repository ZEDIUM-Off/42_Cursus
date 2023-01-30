/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:41:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 13:11:50 by  mchenava        ###   ########lyon.fr   */
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

t_vec2	*compute_pixel(t_3d_env *env);

#endif
