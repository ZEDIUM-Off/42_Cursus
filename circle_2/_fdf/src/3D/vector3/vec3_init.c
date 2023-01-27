/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:24:52 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/25 14:28:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_vec3_method	*vec3_methods(void)
{
	t_vec3_method	*methods;

	methods = (t_vec3_method *)malloc(sizeof(t_vec3_method));
	methods->add = &vec3_add;
	methods->sub = &vec3_sub;
	methods->mult = &vec3_mult;
	methods->div = &vec3_div;
	methods->inv = &vec3_inv;
	methods->crossp = &vec3_crossp;
	methods->dotp = &vec3_dotp;
	methods->norm = &vec3_norm;
	methods->len = &vec3_len;
	methods->mul_mat = &vec3_mul_mat;
	return (methods);
}

t_vec3	*vec3_init(float x, float y, float z)
{
	t_vec3	*vec;

	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}
