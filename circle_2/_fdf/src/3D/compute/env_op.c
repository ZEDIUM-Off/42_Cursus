/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 11:03:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_3d_env	*init_env3d(t_vec4 *cam_pos, float w_w, float w_h)
{
	t_3d_env	*env;

	env = (t_3d_env *)malloc(sizeof(t_3d_env));
	env->cam = cam_init(cam_pos, vec4_init(0, 0, 0, 1), w_w, w_h);
	env->proj = init_proj(env->cam, w_w, w_h);
	return (env);
}
