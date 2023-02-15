/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:37:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 11:12:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	pixel_put(t_mlx_env	*env, int x, int y, int color)
{
	char	*dst;
	int		i;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	i = env->bpp - 8;
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

t_obj	*def_grid(int x, int y)
{
	t_obj		*obj;
	t_vertex	*vertex;
	int			i;
	int			j;

	obj = malloc(sizeof(t_obj));
	vertex = malloc(sizeof(t_vertex));
	obj->vertices = vertex;
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			vertex->coords = vec4_init(j - x / 2, 0, i - y / 2, 1);
			if (i == x - 1 && j == y - 1)
				vertex->next = NULL;
			else
				vertex->next = malloc(sizeof(t_vertex));
			vertex = vertex->next;
			j++;
		}
		i++;
	}
	obj->edges = NULL;
	return (obj);
}

int	main(void)
{
	t_mlx_env	*mlx_env;
	t_obj		*obj;

	mlx_env = init_mlx_env();
	obj = malloc(sizeof(t_obj));
	obj->vertices = malloc(sizeof(t_vertex));
	obj->vertices->coords = vec4_init(0 + 1, 0+ 1, 0+ 1, 1);
	obj->vertices->next = malloc(sizeof(t_vertex));
	obj->vertices->next->coords = vec4_init(0+ 1, 0+ 1, 1+ 1, 1);
	obj->vertices->next->next = malloc(sizeof(t_vertex));
	obj->vertices->next->next->coords = vec4_init(0+ 1, 1+ 1, 0+ 1, 1);
	obj->vertices->next->next->next = malloc(sizeof(t_vertex));
	obj->vertices->next->next->next->coords = vec4_init(0+ 1, 1+ 1, 1+ 1, 1);
	obj->vertices->next->next->next->next = malloc(sizeof(t_vertex));
	obj->vertices->next->next->next->next->coords = vec4_init(1+ 1, 0+ 1, 0+ 1, 1);
	obj->vertices->next->next->next->next->next = malloc(sizeof(t_vertex));
	obj->vertices->next->next->next->next->next->coords = vec4_init(1+ 1, 0+ 1, 1+ 1, 1);
	obj->vertices->next->next->next->next->next->next = malloc(sizeof(t_vertex));
	obj->vertices->next->next->next->next->next->next->coords = vec4_init(1+ 1, 1+ 1, 0+ 1, 1);
	obj->vertices->next->next->next->next->next->next->next = malloc(sizeof(t_vertex));
	obj->vertices->next->next->next->next->next->next->next->coords = vec4_init(1+ 1, 1+ 1, 1+ 1, 1);
	obj->vertices->next->next->next->next->next->next->next->next = NULL;
	obj->edges = malloc(sizeof(t_edge));
	obj->edges->start = obj->vertices->coords;
	obj->edges->end = obj->vertices->next->coords;
	obj->edges->next = malloc(sizeof(t_edge));
	obj->edges->next->start = obj->vertices->next->coords;
	obj->edges->next->end = obj->vertices->next->next->coords;
	obj->edges->next->next = malloc(sizeof(t_edge));
	obj->edges->next->next->start = obj->vertices->next->next->coords;
	obj->edges->next->next->end = obj->vertices->next->next->next->coords;
	obj->edges->next->next->next = malloc(sizeof(t_edge));
	obj->edges->next->next->next->start = obj->vertices->next->next->next->coords;
	obj->edges->next->next->next->end = obj->vertices->next->next->next->next->coords;
	obj->edges->next->next->next->next = malloc(sizeof(t_edge));
	obj->edges->next->next->next->next->start = obj->vertices->next->next->next->next->coords;
	obj->edges->next->next->next->next->end = obj->vertices->next->next->next->next->next->coords;
	obj->edges->next->next->next->next->next = malloc(sizeof(t_edge));
	obj->edges->next->next->next->next->next->start = obj->vertices->next->next->next->next->next->coords;
	obj->edges->next->next->next->next->next->end = obj->vertices->next->next->next->next->next->next->coords;
	obj->edges->next->next->next->next->next->next = malloc(sizeof(t_edge));
	obj->edges->next->next->next->next->next->next->start = obj->vertices->next->next->next->next->next->next->coords;
	obj->edges->next->next->next->next->next->next->end = obj->vertices->next->next->next->next->next->next->next->coords;
	obj->edges->next->next->next->next->next->next->next = NULL;
	mlx_env->env3d->objs = malloc(sizeof(t_obj *) * 3);
	mlx_env->env3d->objs[0] = obj;
	mlx_env->env3d->objs[1] = def_grid(10, 10);
	mlx_env->env3d->objs[2] = NULL;
	update_img(mlx_env);
	mlx_hook(mlx_env->win, 2, 1L << 0, &cam_controls, &mlx_env);
	mlx_loop(mlx_env->mlx);
}
