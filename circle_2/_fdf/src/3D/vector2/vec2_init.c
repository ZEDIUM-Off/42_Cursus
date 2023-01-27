/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_methods3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:54:00 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/25 13:59:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_vec2_method	*vec2_methods(void)
{
	t_vec2_method	*methods;

	methods = (t_vec2_method *)malloc(sizeof(t_vec2_method));
	methods->add = &vec2_add;
	methods->sub = &vec2_sub;
	methods->mult = &vec2_mult;
	methods->div = &vec2_div;
	methods->inv = &vec2_inv;
	methods->crossp = &vec2_crossp;
	methods->dotp = &vec2_dotp;
	methods->norm = &vec2_norm;
	methods->len = &vec2_len;
	return (methods);
}

t_vec2	*vec2_init(float x, float y)
{
	t_vec2	*vec;

	vec = (t_vec2 *)malloc(sizeof(t_vec2));
	vec->x = x;
	vec->y = y;
	vec->methods = vec2_methods();
	return (vec);
}
