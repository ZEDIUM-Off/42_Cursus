/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:52:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 15:22:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_vec2	*vec2_inv(t_vec2 *a)
{
	return (vec2_init(-a->x, -a->y));
}

t_vec2	*vec2_crossp(t_vec2 *a, t_vec2 *b)
{
	return (vec2_init(a->x * b->y, a->y * b->x));
}

float	vec2_dotp(t_vec2 *a, t_vec2 *b)
{
	return (a->x * b->x + a->y * b->y);
}

float	vec2_norm(t_vec2 *a)
{
	return (sqrt(a->x * a->x + a->y * a->y));
}

float	vec2_len(t_vec2 *a)
{
	return (a->x * a->x + a->y * a->y);
}
