/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:07:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:22:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4_H
# define VECTOR4_H

# include "../../matrix/matrix4.h"

typedef struct s_vec4			t_vec4;

struct s_vec4
{
  float	x;
  float	y;
	float	z;
  float	w;
};

t_vec4  *vec4_init(float x, float y, float z,	float w);
t_vec4  *vec4_add(t_vec4 *a, t_vec4 *b);
t_vec4  *vec4_sub(t_vec4 *a, t_vec4 *b);
t_vec4  *vec4_mul(t_vec4 *a, t_vec4 *b);
t_vec4  *vec4_div(t_vec4 *a, t_vec4 *b);
t_vec4  *vec4_scale(t_vec4 *a, float b);
t_vec4  *vec4_inv(t_vec4 *a);
t_vec4  *vec4_crossp(t_vec4 *a, t_vec4 *b);
t_vec4  *vec4_mul_mat(t_mat4 m, t_vec4 *v);
float   vec4_dotp(t_vec4 *a, t_vec4 *b);
float   vec4_norm(t_vec4 *a);
float   vec4_len(t_vec4 *a);

#endif