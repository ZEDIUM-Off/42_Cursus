/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:02:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/10 11:59:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../geom.h"

t_vec4	*vec4_add(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*vec;

	vec = (t_vec4 *)malloc(sizeof(t_vec4));
	vec->x = a->x + b->x;
	vec->y = a->y + b->y;
	vec->z = a->z + b->z;
	vec->w = a->w + b->w;
	return (vec);
}

t_vec4	*vec4_sub(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*vec;

	vec = (t_vec4 *)malloc(sizeof(t_vec4));
	vec->x = a->x - b->x;
	vec->y = a->y - b->y;
	vec->z = a->z - b->z;
	vec->w = a->w - b->w;
	return (vec);
}

t_vec4	*vec4_mul(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*vec;

	vec = (t_vec4 *)malloc(sizeof(t_vec4));
	vec->x = a->x * b->x;
	vec->y = a->y * b->y;
	vec->z = a->z * b->z;
	vec->w = a->w * b->w;
	return (vec);
}

t_vec4	*vec4_div(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*vec;

	vec = (t_vec4 *)malloc(sizeof(t_vec4));
	vec->x = a->x / b->x;
	vec->y = a->y / b->y;
	vec->z = a->z / b->z;
	vec->w = a->w / b->w;
	return (vec);
}

t_vec4	*vec4_scale(t_vec4 *a, float b)
{
	t_vec4	*vec;

	vec = (t_vec4 *)malloc(sizeof(t_vec4));
	vec->x = a->x * b;
	vec->y = a->y * b;
	vec->z = a->z * b;
	vec->w = a->w * b;
	return (vec);
}
