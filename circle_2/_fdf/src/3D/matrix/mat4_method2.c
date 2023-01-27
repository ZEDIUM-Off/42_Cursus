/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_method2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:35:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/26 11:45:40 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_mat4	*mat4_inv(t_mat4 *a)
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
			res->m[i][j] = a->m[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

t_mat4	*transpose(t_mat4 *a)
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
			res->m[i][j] = a->m[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

float[]	mat4_get_row(t_mat4 *a, int row)
{
	float	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(float) * 4);
	while (i < 4)
	{
		res[i] = a->m[row][i];
		i++;
	}
	return (res);
}
