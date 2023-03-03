/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:23:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:28:34 by  mchenava        ###   ########.fr       */
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