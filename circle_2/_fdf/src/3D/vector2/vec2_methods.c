/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:44:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 12:08:11 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_vec2	*vec2_add(t_vec2 *a, t_vec2 *b)
{
	return (vec2_init(a->x + b->x, a->y + b->y));
}

t_vec2	*vec2_sub(t_vec2 *a, t_vec2 *b)
{
	return (vec2_init(a->x - b->x, a->y - b->y));
}

t_vec2	*vec2_mul(t_vec2 *a, t_vec2 *b)
{
	return (vec2_init(a->x * b->x, a->y * b->y));
}

t_vec2	*vec2_div(t_vec2 *a, t_vec2 *b)
{
	return (vec2_init(a->x / b->x, a->y / b->y));
}

t_vec2	*vec2_scale(t_vec2 *a, float b)
{
	return (vec2_init(a->x * b, a->y * b));
}
