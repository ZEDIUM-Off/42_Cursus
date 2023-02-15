/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:59:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 11:06:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	draw_vertex(t_mlx_env *mlx_env, t_vec2 *point, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i * i + j * j <= 4 * 4)
			{
				pixel_put(mlx_env, (int)point->x + i, (int)point->y + j, color);
				pixel_put(mlx_env, (int)point->x - i, (int)point->y + j, color);
				pixel_put(mlx_env, (int)point->x + i, (int)point->y - j, color);
				pixel_put(mlx_env, (int)point->x - i, (int)point->y - j, color);
			}
			j++;
		}
		i++;
	}
}

int	def_steps(t_vec2 *delta)
{
	int	steps;

	if (ft_abs(delta->x) > ft_abs(delta->y))
		steps = ft_abs(delta->x);
	else
		steps = ft_abs(delta->y);
	return (steps);
}

void	draw_edge(t_mlx_env *mlx_env,
	t_vec2 *point1, t_vec2 *point2, int color)
{
	t_vec2	*delta;
	int		steps;
	int		i;

	delta = vec2_sub(point2, point1);
	steps = def_steps(delta);
	i = 0;
	while (i <= steps)
	{
		pixel_put(mlx_env, (int)point1->x, (int)point1->y, color);
		point1 = vec2_add(point1,
				vec2_init(delta->x / steps, delta->y / steps));
		i++;
	}
}

void	draw_object(t_mlx_env *mlx_env, t_obj *object)
{
	t_vec2		*point;
	t_vec2		*point1;
	t_vec2		*point2;
	t_vertex	*tempv;
	t_edge		*tempe;

	tempv = object->vertices;
	tempe = object->edges;
	// point = proj_point(mlx_env->env3d, get_cam_dir(mlx_env->env3d->cam));
	// draw_vertex(mlx_env, point, 0x00FF0000);
	while (tempv)
	{
		point = proj_point(mlx_env->env3d, tempv->coords);
		draw_vertex(mlx_env, point, 0x0000FF00);
		tempv = tempv->next;
	}
	while (tempe)
	{
		point1 = proj_point(mlx_env->env3d, tempe->start);
		point2 = proj_point(mlx_env->env3d, tempe->end);
		draw_edge(mlx_env, point1, point2, 0x00FF0000);
		tempe = tempe->next;
	}
	// free(point);
	// free(point1);
	// free(point2);
}
