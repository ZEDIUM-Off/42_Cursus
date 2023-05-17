/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:48:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/17 11:11:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	clean_fdf(t_fdf *fdf)
{
	if (fdf->status >= MAP_ERROR)
		if (fdf->map)
			free(fdf->map);
	if (fdf->status >= IND_ERROR)
		if (fdf->indices)
			free(fdf->indices);
	if (fdf->status >= GLX_ERROR)
		free_gl_context(&fdf->glx);
}
