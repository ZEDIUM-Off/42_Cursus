/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:02:36 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:04:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vec2			t_vec2;

struct s_vec2
{
	float			x;
	float			y;
};

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

#endif