/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/31 13:21:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_3d_env	*init_env3D(void)
{
	t_3d_env	*env;

	env = (t_3d_env *)malloc(sizeof(t_3d_env));
	env->cam = init_cam(vec3_init(-5,6, -55));
	env->proj = init_proj(env->cam);
	return (env);
}