/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:13:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/06 16:20:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"


void clear_img(t_mlx_env *mlx_env)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(mlx_env, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void draw_circle(t_mlx_env *mlx_env, int x, int y, int radius, int color)
{
	int i;
	int j;

  for (i = 0; i < radius; i++)
	{
		for (j = 0; j < radius; j++)
		{
			if (i * i + j * j <= radius * radius && x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
			{
				my_mlx_pixel_put(mlx_env, x + i, y + j, color);
				my_mlx_pixel_put(mlx_env, x - i, y + j, color);
				my_mlx_pixel_put(mlx_env, x + i, y - j, color);
				my_mlx_pixel_put(mlx_env, x - i, y - j, color);
			}
		}
	}
}

void	update_img(t_mlx_env *mlx_env, t_vec4 *cube[8])
{
	t_vec2 *pixel;

	clear_img(mlx_env);
	for (int i = 0; i < 8; i++)
	{
		pixel = proj_point(mlx_env->env3d, cube[i]);
		draw_circle(mlx_env, (int)pixel->x, (int)pixel->y, 4, 0x0000FF00);
	}
	mlx_put_image_to_window(mlx_env->mlx, mlx_env->win, mlx_env->img, 0, 0);
}