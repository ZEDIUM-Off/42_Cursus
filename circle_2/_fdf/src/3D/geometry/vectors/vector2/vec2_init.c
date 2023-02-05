/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:54:00 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:23:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../geom.h"

t_vec2	*vec2_init(float x, float y)
{
	t_vec2	*vec;

	vec = (t_vec2 *)malloc(sizeof(t_vec2));
	vec->x = x;
	vec->y = y;
	return (vec);
}
