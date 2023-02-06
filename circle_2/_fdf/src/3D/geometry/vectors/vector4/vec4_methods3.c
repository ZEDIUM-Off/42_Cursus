/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_methods3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:05:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:24:58 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../geom.h"

float	vec4_len(t_vec4 *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
}