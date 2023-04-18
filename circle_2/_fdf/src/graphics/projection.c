/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:13:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/17 12:05:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//mat4 -> float[4][4]

t_mat4	mat4_rotate_x(float angle)
{
	t_mat4	rot;

	rot = identity_mat4();
	rot[1][1] = cos(angle);
	rot[1][2] = -sin(angle);
	rot[2][1] = sin(angle);
	rot[2][2] = cos(angle);
	return (rot);
}

t_mat4	mat4_rotate_y(float angle)
{
	t_mat4	rot;

	rot = identity_mat4();
	rot[0][0] = cos(angle);
	rot[0][2] = sin(angle);
	rot[2][0] = -sin(angle);
	rot[2][2] = cos(angle);
	return (rot);
}

t_mat4	isometric_view(void)
{
	t_mat4	view;

	view = identity_mat4();
	view[0][0] = 0.707;
	view[0][1] = 0.0;
	view[0][2] = 0.707;
	view[1][0] = 0.408;
	view[1][1] = 0.816;
	view[1][2] = -0.408;
	view[2][0] = -0.577;
	view[2][1] = 0.577;
	view[2][2] = 0.577;
	return (view);
}