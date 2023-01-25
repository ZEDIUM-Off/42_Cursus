/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:08:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/25 11:56:35 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOM_H
# define GEOM_H

typedef struct s_vec3			t_vec3;
typedef struct s_vec3_method	t_vec3_method;

struct s_vec3_method
{
	t_vec3	(*add)(t_vec3, t_vec3);
	t_vec3	(*sub)(t_vec3, t_vec3);
	t_vec3	(*mul)(t_vec3, t_vec3);
	t_vec3	(*scale)(t_vec3, float);
	t_vec3	(*inv)(t_vec3);
	t_vec3	(*crossp)(t_vec3, t_vec3);
	float		(*dotp)(t_vec3, t_vec3);
	float		(*norm)(t_vec3);
	float		(*len)(t_vec3);
};

struct s_vec3
{
	float			x;
	float			y;
	float			z;
	t_vec3_method	*methods;
};

#endif