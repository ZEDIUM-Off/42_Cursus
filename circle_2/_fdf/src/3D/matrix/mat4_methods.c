/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:30:31 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 15:17:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_mat4	def_mat(void)
{
	float	**mat;
	int		i;
	int		j;

	mat = malloc(sizeof(float *) * 4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
	return (mat);
}

t_mat4	mat4_add(t_mat4 *a, t_mat4 *b)
{
	t_mat4	res;
	int		i;
	int		j;

	i = 0;
	res = def_mat();
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = *a[i][j] + *b[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

t_mat4	mat4_sub(t_mat4 *a, t_mat4 *b)
{
	t_mat4	res;
	int		i;
	int		j;

	i = 0;
	res = def_mat();
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = *a[i][j] - *b[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

t_mat4	mat4_mul(t_mat4 *a, t_mat4 *b)
{
	t_mat4	res;
	int		i;
	int		j;
	int		k;

	i = 0;
	res = def_mat();
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				res[i][j] += *a[i][k] * *b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

t_mat4	mat4_div(t_mat4 *a, t_mat4 *b)
{
	t_mat4	res;
	int		i;
	int		j;

	i = 0;
	res = def_mat();
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = *a[i][j] / *b[i][j];
			j++;
		}
		i++;
	}
	return (res);
}
