/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:08:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/26 11:57:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOM_H
# define GEOM_H

typedef struct s_vec3			t_vec3;
typedef struct s_vec3_method	t_vec3_method;

typedef struct s_vec3			t_vec2;
typedef struct s_vec3_method	t_vec2_method;

typedef struct s_mat4			t_mat4;
typedef struct s_mat4_method	t_mat4_method;

struct s_vec2
{
	float			x;
	float			y;
	t_vec2_method	*methods;
};

struct s_vec2_method
{
	t_vec2*	(*add)(t_vec2*, t_vec2*);
	t_vec2*	(*sub)(t_vec2*, t_vec2*);
	t_vec2*	(*mul)(t_vec2*, t_vec2*);
	t_vec2*	(*div)(t_vec2*, t_vec2*);
	t_vec2*	(*scale)(t_vec2*, float);
	t_vec2*	(*inv)(t_vec2*);
	t_vec2*	(*crossp)(t_vec2*, t_vec2*);
	float		(*dotp)(t_vec2*, t_vec2*);
	float		(*norm)(t_vec2*);
	float		(*len)(t_vec2*);
};

struct s_vec3
{
	float			x;
	float			y;
	float			z;
	t_vec3_method	*methods;
};

struct s_vec3_method
{
	t_vec3*	(*add)(t_vec3*, t_vec3*);
	t_vec3*	(*sub)(t_vec3*, t_vec3*);
	t_vec3*	(*mul)(t_vec3*, t_vec3*);
	t_vec3*	(*div)(t_vec3*, t_vec3*);
	t_vec3*	(*scale)(t_vec3*, float);
	t_vec3*	(*inv)(t_vec3*);
	t_vec3*	(*crossp)(t_vec3*, t_vec3*);
	t_vec3*	(*mul_mat)(t_mat4*, t_vec3*);
	float		(*dotp)(t_vec3*, t_vec3*);
	float		(*norm)(t_vec3*);
	float		(*len)(t_vec3*);
};

struct s_mat4
{
	float			m[4][4];
	t_mat4_method	*methods;
};

struct s_mat4_method
{
	float []	(*get_row)(t_mat4*, int);
	t_mat4*		(*add)(t_mat4*, t_mat4*);
	t_mat4* 	(*sub)(t_mat4*, t_mat4*);
	t_mat4* 	(*mul)(t_mat4*, t_mat4*);
	t_mat4* 	(*div)(t_mat4*, t_mat4*);
	t_mat4* 	(*scale)(t_mat4*, float);
	t_mat4* 	(*inv)(t_mat4*);
	t_mat4* 	(*transpose)(t_mat4*);
};

t_vec3	*vec3_init(float x, float y, float z);
t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_sub(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_mul(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_div(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_scale(t_vec3 *a, float b);
t_vec3	*vec3_inv(t_vec3 *a);
t_vec3	*vec3_crossp(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_mul_mat(t_matrix4 *m, t_vec3 *v);
float	vec3_dotp(t_vec3 *a, t_vec3 *b);
float	vec3_norm(t_vec3 *a);
t_vec3	*vec3_len(t_vec3 *a);

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

t_mat4	*mat4_init(float **tab);
t_mat4	*mat4_add(t_mat4 *a, t_mat4 *b);
t_mat4	*mat4_sub(t_mat4 *a, t_mat4 *b);
t_mat4	*mat4_mul(t_mat4 *a, t_mat4 *b);
t_mat4	*mat4_div(t_mat4 *a, t_mat4 *b);
t_mat4	*mat4_scale(t_mat4 *a, float b);
t_mat4	*mat4_inv(t_mat4 *a);
t_mat4	*transpose(t_mat4 *a);
float[]	mat4_get_row(t_mat4 *a, int row);

#endif