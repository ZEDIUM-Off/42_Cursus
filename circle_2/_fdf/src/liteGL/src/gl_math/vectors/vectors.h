/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:50:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 10:52:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <lite_gl.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

#endif