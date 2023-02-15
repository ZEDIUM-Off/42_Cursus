/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/10 13:58:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

t_mlx_env	*init_mlx_env(void)
{
	t_mlx_env	*mlx_env;

	mlx_env = malloc(sizeof(t_mlx_env));
	mlx_env->mlx = mlx_init();
	mlx_env->win = mlx_new_window(mlx_env->mlx,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_env->img = mlx_new_image(mlx_env->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_env->img_addr = mlx_get_data_addr(mlx_env->img,
			&mlx_env->bpp, &mlx_env->line_len, &mlx_env->endian);
	mlx_env->env3d = init_env3D(vec4_init(0, 1, -10, 1),
			WIN_WIDTH, WIN_HEIGHT);
	return (mlx_env);
}
