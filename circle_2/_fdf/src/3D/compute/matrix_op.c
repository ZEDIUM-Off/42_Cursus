/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:53:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/15 11:01:11 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env3D.h"

t_mat4	translate(t_vec3	*pos)
{
	t_mat4	res;

	res = def_mat();
	res[0][0] = 1;
	res[1][1] = 1;
	res[2][2] = 1;
	res[3][3] = 1;
	res[0][3] = pos->x;
	res[1][3] = pos->y;
	res[2][3] = pos->z;
	return (res);
}

t_mat4	scale(float scale)
{
	t_mat4	res;

	res = def_mat();
	res[0][0] = scale;
	res[1][1] = scale;
	res[2][2] = scale;
	res[3][3] = 1;
	return (res);
}

t_mat4	rotate_x(float angle)
{
	t_mat4	res;

	res = def_mat();
	res[0][0] = 1;
	res[3][3] = 1;
	res[1][1] = cos(angle);
	res[1][2] = sin(angle);
	res[2][1] = -sin(angle);
	res[2][2] = cos(angle);
	return (res);
}

t_mat4	rotate_y(float angle)
{
	t_mat4	res;

	res = def_mat();
	res[1][1] = 1;
	res[3][3] = 1;
	res[0][0] = cos(angle);
	res[0][2] = -sin(angle);
	res[2][0] = sin(angle);
	res[2][2] = cos(angle);
	return (res);
}

t_mat4	rotate_z(float angle)
{
	t_mat4	res;

	res = def_mat();
	res[2][2] = 1;
	res[3][3] = 1;
	res[0][0] = cos(angle);
	res[0][1] = sin(angle);
	res[1][0] = -sin(angle);
	res[1][1] = cos(angle);
	return (res);
}
