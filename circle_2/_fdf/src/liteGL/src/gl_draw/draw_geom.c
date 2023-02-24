/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_geom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:50:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/24 15:11:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>
//dans le context , ce qui represente "l'image de la mlx " c'est back_buffer.buf 
void	draw_pixel(t_vec4 cf, int x, int y, int z)
{
	if (x >= 0 && x < c->width && y >= 0 && y < c->height)
	{
		if (z < c->depthbuffer[y * c->width + x])
		{
			c->framebuffer[y * c->width + x] = c->color;
			c->depthbuffer[y * c->width + x] = z;
		}
	}
}

void	draw_point(t_glvert *vert)
{
	int	x;
	int	y;

	x = (int)vert->screen_space.x;
	y = (int)vert->screen_space.y;
	if (x >= 0 && x < c->width && y >= 0 && y < c->height)
		c->framebuffer[y * c->width + x] = c->color;
}
