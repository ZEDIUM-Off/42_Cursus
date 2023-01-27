/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:30:31 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/26 11:45:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_mat4	*mat4_add(t_mat4 *a, t_mat4 *b)
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
			res->m[i][j] = a->m[i][j] + b->m[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

t_mat4	*mat4_sub(t_mat4 *a, t_mat4 *b)
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
			res->m[i][j] = a->m[i][j] - b->m[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

t_mat4	*mat4_mul(t_mat4 *a, t_mat4 *b)
{
	t_mat4	*res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	res = malloc(sizeof(t_mat4));
	while (i < 4)
	{
		while (j < 4)
		{
			while (k < 4)
			{
				res->m[i][j] += a->m[i][k] * b->m[k][j];
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

t_mat4	*mat4_div(t_mat4 *a, t_mat4 *b)
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
			res->m[i][j] = a->m[i][j] / b->m[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

t_mat4	*mat4_scale(t_mat4 *a, float b)
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
			res->m[i][j] = a->m[i][j] * b;
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}
