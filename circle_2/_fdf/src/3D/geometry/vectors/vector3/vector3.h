/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:05:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:06:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vec3			t_vec3;

struct s_vec3
{
	float			x;
	float			y;
	float			z;
};

t_vec3	*vec3_init(float x, float y, float z);
t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_sub(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_mul(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_div(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_scale(t_vec3 *a, float b);
t_vec3	*vec3_inv(t_vec3 *a);
t_vec3	*vec3_crossp(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_mul_mat(t_mat4 m, t_vec3 *v);
float	vec3_dotp(t_vec3 *a, t_vec3 *b);
float	vec3_norm(t_vec3 *a);
float	vec3_len(t_vec3 *a);

#endif