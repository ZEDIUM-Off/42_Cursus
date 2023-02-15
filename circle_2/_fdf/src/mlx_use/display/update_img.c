/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:13:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/08 13:26:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	clear_img(t_mlx_env *mlx_env)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_put(mlx_env, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	update_img(t_mlx_env *mlx_env)
{
	int		i;

	clear_img(mlx_env);
	i = 0;
	while (mlx_env->env3d->objs[i])
	{
		draw_object(mlx_env, mlx_env->env3d->objs[i]);
		i++;
	}
	mlx_put_image_to_window(mlx_env->mlx, mlx_env->win, mlx_env->img, 0, 0);
}
