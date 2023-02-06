/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:37:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/06 16:18:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <X11/keysym.h>
#include "env3D.h"
#include "main.h"

void	my_mlx_pixel_put(t_mlx_env	*env, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = env->bpp - 8;
	//printf("to draw : x=%d, y=%d \n", x, y);
	dst = env->img_addr + (y * env->line_len + x * (env->bpp / 8));
	while (i >= 0)
	{
		if (env->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (env->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}


int	main(void)
{
	t_mlx_env	*mlx_env;
	// t_vec4	*cube[8];

	mlx_env = init_mlx_env();
	mlx_env->cube[0] = vec4_init(0, 0, 0, 1);
	mlx_env->cube[1] = vec4_init(0, 0, 1, 1);
	mlx_env->cube[2] = vec4_init(0, 1, 0, 1);
	mlx_env->cube[3] = vec4_init(0, 1, 1, 1);
	mlx_env->cube[4] = vec4_init(1, 0, 0, 1);
	mlx_env->cube[5] = vec4_init(1, 0, 1, 1);
	mlx_env->cube[6] = vec4_init(1, 1, 0, 1);
	mlx_env->cube[7] = vec4_init(1, 1, 1, 1);
	update_img(mlx_env, mlx_env->cube);
	// mlx_mouse_hook(mlx_env->win, &test, &env);
	mlx_hook(mlx_env->win, 2,1L<<0, &cam_controls, &mlx_env);
	// update_img(mlx_env cube);
	mlx_loop(mlx_env->mlx);
}
