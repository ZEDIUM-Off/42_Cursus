/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:08:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/30 15:45:11 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOM_H
# define GEOM_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vec3			t_vec3;

typedef struct s_vec2			t_vec2;

typedef float					**t_mat4;

struct s_vec2
{
	float			x;
	float			y;
};

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
t_vec3	*vec3_mul_mat(t_mat4 *m, t_vec3 *v);
float	vec3_dotp(t_vec3 *a, t_vec3 *b);
float	vec3_norm(t_vec3 *a);
float	vec3_len(t_vec3 *a);

t_vec2	*vec2_init(float x, float y);
t_vec2	*vec2_add(t_vec2 *a, t_vec2 *b);
t_vec2	*vec2_sub(t_vec2 *a, t_vec2 *b);
t_vec2	*vec2_mul(t_vec2 *a, t_vec2 *b);
t_vec2	*vec2_div(t_vec2 *a, t_vec2 *b);
t_vec2	*vec2_scale(t_vec2 *a, float b);
t_vec2	*vec2_inv(t_vec2 *a);
t_vec2	*vec2_crossp(t_vec2 *a, t_vec2 *b);
float	vec2_dotp(t_vec2 *a, t_vec2 *b);
float	vec2_norm(t_vec2 *a);
float	vec2_len(t_vec2 *a);

t_mat4	def_mat(void);
t_mat4	mat4_add(t_mat4 *a, t_mat4 *b);
t_mat4	mat4_sub(t_mat4 *a, t_mat4 *b);
t_mat4	mat4_mul(t_mat4 *a, t_mat4 *b);
t_mat4	mat4_div(t_mat4 *a, t_mat4 *b);
t_mat4	mat4_scale(t_mat4 *a, float b);
t_mat4	mat4_inv(t_mat4 *a);
t_mat4	mat4_transpose(t_mat4 *a);

#endif