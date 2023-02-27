/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:01:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/27 14:26:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lite_gl.h"

void	set_lines(t_vec3 *hp, t_vec3 **l)
{
	*l[0] = vec3_init(hp[0].y - hp[1].y, hp[0].x - hp[1].x, hp[0].x * hp[1].y
			- hp[1].x * hp[0].y);
	*l[1] = vec3_init(hp[1].y - hp[2].y, hp[1].x - hp[2].x, hp[1].x * hp[2].y
			- hp[2].x * hp[1].y);
	*l[2] = vec3_init(hp[2].y - hp[0].y, hp[2].x - hp[0].x, hp[2].x * hp[0].y
			- hp[0].x * hp[2].y);
}

void	set_abg(float **abg, t_vec3 *hp, t_vec3 *lines, float fx, float fy)
{
	*abg[2] = lines[0].x * fx + lines[0].y * fy + lines[0].z / \
	lines[0].x * hp[2].x + lines[0].y * hp[2].y + lines[0].z;
	*abg[1] = lines[1].x * fx + lines[1].y * fy + lines[1].z / \
	lines[1].x * hp[0].x + lines[1].y * hp[0].y + lines[1].z;
	*abg[0] = 1 - *abg[1] - *abg[2];
}

void	draw_tri_loop(t_vec3 *hp, int *x, int *y, float *abg)
{
	t_vec3	lines[3];
	int		iy;
	int		ix;
	float	fx;
	float	fy;

	set_lines(hp, &lines);
	iy = y[0];
	while (iy <= y[1])
	{
		y = iy + 0.5f;
		ix = x[0];
		while (ix <= x[1])
		{
			x = ix + 0.5f;
			set_abg(&abg, hp, lines, fx, fy);
			if (abg[0] >= 0 && abg[1] >= 0 && abg[2] >= 0)
				pixel_put(mlx_env, x, y, color);
			ix++;
		}
		iy++;
	}
}

void	draw_triangle_fill(glVertex *v0, glVertex *v1,
	glVertex *v2, unsigned int provoke)
{
	t_vec4	p[3];
	t_vec3	hp[3];
	int		x[2];
	int		y[2];
	float	abg[3];

	p[0] = v0->screen_space;
	p[1] = v1->screen_space;
	p[2] = v2->screen_space;
	hp[0] = vec3_init(p[0].x, p[0].y, p[0].z);
	hp[1] = vec3_init(p[1].x, p[1].y, p[1].z);
	hp[2] = vec3_init(p[2].x, p[2].y, p[2].z);
	x[0] = (int)min3(h[0].x, h[1].x, h[2].x);
	x[1] = (int)max3(h[0].x, h[1].x, h[2].x);
	y[0] = (int)min3(h[0].y, h[1].y, h[2].y);
	y[1] = (int)max3(h[0].y, h[1].y, h[2].y);
	draw_tri_loop(hp, x, y, abg);
}

void	draw_triangle_final(glVertex *v0, glVertex *v1,
	glVertex *v2, unsigned int provoke)
{
	int	front_facing;

	v0->screen_space = mult_mat4_vec4(c->vp_mat, v0->clip_space);
	v1->screen_space = mult_mat4_vec4(c->vp_mat, v1->clip_space);
	v2->screen_space = mult_mat4_vec4(c->vp_mat, v2->clip_space);
	front_facing = is_front_facing(v0, v1, v2);
	if (c->cull_face)
	{
		if (c->cull_mode == GL_FRONT_AND_BACK)
			return ;
		if (c->cull_mode == GL_BACK && !front_facing)
			return ;
		if (c->cull_mode == GL_FRONT && front_facing)
			return ;
	}
	draw_triangle_fill(v0, v1, v2, provoke);
}

void	draw_triangle(glVertex *v0, glVertex *v1,
	glVertex *v2, unsigned int provoke)
{
	int	c_or;
	int	c_and;

	c_and = v0->clip_code & v1->clip_code & v2->clip_code;
	if (c_and != 0)
		return ;
	c_or = v0->clip_code | v1->clip_code | v2->clip_code;
	if (c_or == 0)
		draw_triangle_final(v0, v1, v2, provoke);
	else
		draw_triangle_clip(v0, v1, v2, provoke, 0);
}
