/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_glx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:00:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/05 14:04:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	setup_gl_context(t_fdf *fdf)
{
	t_mlx_env		*mxv;
	t_gl_context	*c;

	mxv = &fdf->mxv;
	c = &fdf->glx;
	if (!init_gl_context(c, (t_context_settings){
			(t_u32 **)&mxv->img->data, WIDTH, HEIGHT, 32,
			0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000}))
	{
		ft_printf(2, "Failed to initialize glContext");
		exit(0);
	}
}
