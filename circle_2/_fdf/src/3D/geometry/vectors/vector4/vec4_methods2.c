/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:04:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 11:04:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../geom.h"

t_vec4	*vec4_inv(t_vec4 *a)
{
	return (vec4_init(-a->x, -a->y, -a->z, -a->w));
}

t_vec4	*vec4_crossp(t_vec4 *a, t_vec4 *b)
{
	return (vec4_init(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z, a->x * b->y - a->y * b->x, 1));
}

t_vec4	*vec4_mul_mat(t_mat4 m, t_vec4 *v)
{
	return (vec4_init(
			m[0][0] * v->x + m[1][0] * v->y + m[2][0] * v->z + m[3][0] * v->w,
			m[0][1] * v->x + m[1][1] * v->y + m[2][1] * v->z + m[3][1] * v->w,
			m[0][2] * v->x + m[1][2] * v->y + m[2][2] * v->z + m[3][2] * v->w,
			m[0][3] * v->x + m[1][3] * v->y + m[2][3] * v->z + m[3][3] * v->w));
}

float	vec4_dotp(t_vec4 *a, t_vec4 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
}

t_vec4	*vec4_norm(t_vec4 *a)
{
	return (vec4_init(a->x / vec4_len(a), a->y / vec4_len(a),
			a->z / vec4_len(a), a->w / vec4_len(a)));
}
