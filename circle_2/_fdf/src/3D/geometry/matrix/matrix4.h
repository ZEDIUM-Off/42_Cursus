/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:01:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:05:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4_H
# define MATRIX4_H

typedef float					**t_mat4;

t_mat4	def_mat(void);
t_mat4	mat4_add(t_mat4 a, t_mat4 b);
t_mat4	mat4_sub(t_mat4 a, t_mat4 b);
t_mat4	mat4_mul(t_mat4 a, t_mat4 b);
t_mat4	mat4_div(t_mat4 a, t_mat4 b);
t_mat4	mat4_scale(t_mat4 a, float b);
t_mat4	mat4_inv(t_mat4 a);
t_mat4	mat4_transpose(t_mat4 a);
t_mat4	mat4_new(float mat[4][4]);
void mat4_print(t_mat4 a);

#endif