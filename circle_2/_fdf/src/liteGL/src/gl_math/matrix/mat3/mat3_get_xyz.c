/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_extact_xyz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:37:00 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 16:38:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec3	x_mat3(t_mat3 m)
{
	return (make_vec3(m[0][0], m[0][1], m[0][2]));
}

t_vec3	y_mat3(t_mat3 m)
{
	return (make_vec3(m[1][0], m[1][1], m[1][2]));
}

t_vec3	z_mat3(t_mat3 m)
{
	return (make_vec3(m[2][0], m[2][1], m[2][2]));
}