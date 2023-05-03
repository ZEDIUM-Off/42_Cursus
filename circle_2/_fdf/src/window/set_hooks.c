/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:59:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 15:15:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <time.h>

void	set_mouse_hooks(t_fdf	*fdf)
{
	mlx_hook(fdf->mxv.win,
		BUTTON_PRESSED_EVT, BUTTON_PRESSED_MASK, mouse_pressed, fdf);
	mlx_hook(fdf->mxv.win,
		BUTTON_RELEASED_EVT, BUTTON_RELEASED_MASK, mouse_released, fdf);
	mlx_hook(fdf->mxv.win,
		MOUSE_MOVE_EVT, MOUSE_MOVE_MASK, mouse_move, fdf);
}

int	render(t_fdf *fdf)
{
	time_t	current_time;

	draw_map(fdf);
	current_time = time(NULL);
	if (current_time - fdf->runtime == 1)
	{
		printf("FPS = %ld\n", fdf->images / (current_time - fdf->runtime));
		fdf->runtime = time(NULL);
		fdf->images = 0;
		printf("loop_count = %ld\n", fdf->loop_ctr);
			fdf->loop_ctr = 0;
	}
	fdf->loop_ctr++;
	return (0);
}

void	set_hooks(t_fdf	*fdf)
{
	set_mouse_hooks(fdf);
	mlx_loop_hook(fdf->mxv.mlx, render, fdf);
	printf("hooks setted\n");
}
