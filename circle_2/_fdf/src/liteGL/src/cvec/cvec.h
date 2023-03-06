/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:23:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/05 21:18:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_H
# define CVEC_H

# include <lite_gl.h>

# define CVEC_FLOAT_SZ 50

typedef struct cvector_float
{
	float	*a;
	size_t	size;
	size_t	capacity;
}	t_cvector_float;

typedef struct cvector_glVertex_Array
{
	t_glVertex_Array	*a;
	size_t				size;
	size_t				capacity;
}	t_cvector_gl_vertex_array;

typedef struct t_cvector_gl_buffer
{
	t_gl_buffer	*a;
	size_t		size;
	size_t		capacity;
}	t_t_cvector_gl_buffer;