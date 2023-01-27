/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:44:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/25 13:53:08 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

// t_vec2	(*add)(t_vec2, t_vec2);
// t_vec2	(*sub)(t_vec2, t_vec2);
// t_vec2	(*mul)(t_vec2, t_vec2);
// t_vec2	(*div)(t_vec2, t_vec2);
// t_vec2	(*scale)(t_vec2, float);
// t_vec2	(*inv)(t_vec2);
// t_vec2	(*crossp)(t_vec2, t_vec2);
// float		(*dotp)(t_vec2, t_vec2);
// float		(*norm)(t_vec2);
// float		(*len)(t_vec2);

t_vec2	*vec2_add(t_vec2 *a, t_vec2 *b)
{
	return ((t_vec2){a.x + b.x, a.y + b.y});
}

t_vec2	*vec2_sub(t_vec2 *a, t_vec2 *b)
{
	return ((t_vec2){a.x - b.x, a.y - b.y});
}

t_vec2	*vec2_mul(t_vec2 *a, t_vec2 *b)
{
	return ((t_vec2){a.x * b.x, a.y * b.y});
}

t_vec2	*vec2_div(t_vec2 *a, t_vec2 *b)
{
	return ((t_vec2){a.x / b.x, a.y / b.y});
}

t_vec2	*vec2_scale(t_vec2 *a, float b)
{
	return ((t_vec2){a.x * b, a.y * b});
}
