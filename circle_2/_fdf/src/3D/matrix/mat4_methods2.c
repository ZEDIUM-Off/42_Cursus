/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:35:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 15:21:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geom.h"

t_mat4	mat4_inv(t_mat4 *a)
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
			res[i][j] = *a[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

t_mat4	mat4_transpose(t_mat4 *a)
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
			res[i][j] = *a[j][i];
			j++;
		}
		i++;
	}
	return (res);
}

t_mat4	mat4_scale(t_mat4 *a, float b)
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
			res[i][j] = *a[i][j] * b;
			j++;
		}
		i++;
	}
	return (res);
}
