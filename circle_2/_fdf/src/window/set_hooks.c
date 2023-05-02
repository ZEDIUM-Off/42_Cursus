/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:59:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/02 15:18:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_mouse_hooks(t_fdf	*fdf)
{
	mlx_hook(fdf->mxv.win,
		BUTTON_PRESSED_EVT, BUTTON_PRESSED_MASK, mouse_pressed, fdf);
	mlx_hook(fdf->mxv.win,
		BUTTON_RELEASED_EVT, BUTTON_RELEASED_MASK, mouse_released, fdf);
	mlx_hook(fdf->mxv.win,
		MOUSE_MOVE_EVT, MOUSE_MOVE_MASK, mouse_move, fdf);
}

void	set_hooks(t_fdf	*fdf)
{
	set_mouse_hooks(fdf);
	printf("hooks setted\n");
}
