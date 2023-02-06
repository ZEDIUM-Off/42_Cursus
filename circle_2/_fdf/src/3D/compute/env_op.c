/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/02 12:12:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_3d_env	*init_env3D(t_vec4 *cam_pos)
{
	t_3d_env	*env;

	env = (t_3d_env *)malloc(sizeof(t_3d_env));
	env->cam = cam_init(cam_pos);
	env->proj = init_proj(env->cam);
	return (env);
}