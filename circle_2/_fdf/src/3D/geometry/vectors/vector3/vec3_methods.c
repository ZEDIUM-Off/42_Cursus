/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:03:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:24:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../geom.h"

t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b)
{
	return (vec3_init(a->x + b->x, a->y + b->y, a->z + b->z));
}

t_vec3	*vec3_sub(t_vec3 *a, t_vec3 *b)
{
	return (vec3_init(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vec3	*vec3_mul(t_vec3 *a, t_vec3 *b)
{
	return (vec3_init(a->x * b->x, a->y * b->y, a->z * b->z));
}

t_vec3	*vec3_div(t_vec3 *a, t_vec3 *b)
{
	return (vec3_init(a->x / b->x, a->y / b->y, a->z / b->z));
}

t_vec3	*vec3_scale(t_vec3 *a, float b)
{
	return (vec3_init(a->x * b, a->y * b, a->z * b));
}
