/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_glx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:00:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/27 11:51:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	setup_gl_context(t_fdf *fdf)
{
	t_mlx_env			*mxv;
	t_gl_context		*c;
	t_context_settings	settings;

	mxv = &fdf->mxv;
	c = &fdf->glx;
	settings.back = (t_u32 **)&mxv->img->data;
	settings.w = WIDTH;
	settings.h = HEIGHT;
	settings.bitdepth = 32;
	settings.r_mask = 0x00FF0000;
	settings.g_mask = 0x0000FF00;
	settings.b_mask = 0x000000FF;
	settings.a_mask = 0xFF000000;
	if (!init_gl_context(c, settings))
	{
		ft_printf(2, "Failed to initialize glContext");
		exit(0);
	}
	gl_clear_color(c, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
}
