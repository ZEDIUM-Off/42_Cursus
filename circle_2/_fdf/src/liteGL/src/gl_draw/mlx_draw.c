/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/27 12:37:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lite_gl.h"

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

void	draw_pixel(t_vec4 cf, int x, int y, float z)
{
	float	dest_depth;
	float	src_depth;
	int		depth_result;

	if (c->scissor_test)
		if (x < c->scissor_lx
			|| y < c->scissor_ly || x >= c->scissor_ux || y >= c->scissor_uy)
			return ;
	if (c->depth_test)
	{
		dest_depth = ((float *)c->zbuf.lastrow)[-y * c->zbuf.w + x];
		src_depth = z;
		if (!(src_depth > dest_depth))
			return ;
		((float *)c->zbuf.lastrow)[-y * c->zbuf.w + x] = src_depth;
	}
	cf.x = clampf_01(cf.x);
	cf.y = clampf_01(cf.y);
	cf.z = clampf_01(cf.z);
	cf.w = clampf_01(cf.w);
	pixel_put(c->mlx_env, x, y, c->color);
}
