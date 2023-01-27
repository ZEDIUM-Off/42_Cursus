/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:50:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/25 14:54:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

	// float[]		(*get_row)(t_mat4*, int);
	// t_mat4*	(*add)(t_mat4*, t_mat4*);
	// t_mat4* (*sub)(t_mat4*, t_mat4*);
	// t_mat4* (*mul)(t_mat4*, t_mat4*);
	// t_mat4* (*div)(t_mat4*, t_mat4*);
	// t_mat4* (*scale)(t_mat4*, float);
	// t_mat4* (*inv)(t_mat4*);
	// t_mat4* (*transpose)(t_mat4*);

t_mat4_method	*mat4_methods(void)
{
	t_mat4_method	*res;

	res = malloc(sizeof(t_mat4_method));
	res->get_row = &mat4_get_row;
	res->add = &mat4_add;
	res->sub = &mat4_sub;
	res->mul = &mat4_mul;
	res->div = &mat4_div;
	res->scale = &mat4_scale;
	res->inv = &mat4_inv;
	res->transpose = &mat4_transpose;
	return (res);
}

t_mat4	*mat4_init(float **tab)
{
	t_mat4	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(t_mat4));
	while (i < 4)
	{
		while (j < 4)
		{
			res->m[i][j] = tab[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	res->methods = mat4_methods();
	return (res);
}
