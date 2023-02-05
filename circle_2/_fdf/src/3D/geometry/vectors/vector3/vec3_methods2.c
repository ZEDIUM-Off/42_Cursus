/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:03:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:24:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../geom.h"

t_vec3	*vec3_inv(t_vec3 *a)
{
	return (vec3_init(-a->x, -a->y, -a->z));
}

t_vec3	*vec3_crossp(t_vec3 *a, t_vec3 *b)
{
	return (vec3_init(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z, a->x * b->y - a->y * b->x));
}

t_vec3	*vec3_mul_mat(t_mat4 m, t_vec3 *v)
{
	return (vec3_init(
			m[0][0] * v->x + m[0][1] * v->y + m[0][2] * v->z + m[0][3],
	m[1][0] * v->x + m[1][1] * v->y + m[1][2] * v->z + m[1][3],
	m[2][0] * v->x + m[2][1] * v->y + m[2][2] * v->z + m[2][3]));
}

float	vec3_dotp(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float	vec3_norm(t_vec3 *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}
