/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:27:31 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 15:00:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mouse_pressed(int btn, int x, int y, t_fdf *fdf)
{
	t_ctrl	*ctrl;
	t_cam		*cam;

	ctrl = (t_ctrl *)&fdf->ctrl;
	cam = (t_cam *)&fdf->cam;
	if (btn == LEFT_CLICK)
	{
		ctrl->rotate = true;
		ctrl->mouse_pos = (t_vec2){x, y};
	}
	if (btn == RIGHT_CLICK)
	{
		ctrl->translate = true;
		ctrl->mouse_pos = (t_vec2){x, y};
	}
	if (btn == SCROLL_UP)
	{
		cam->zoom -= 0.5;
		// draw_map(fdf);
	}
	if (btn == SCROLL_DOWN)
	{
		cam->zoom += 0.5;
		// draw_map(fdf);
	}
	return (0);
}

int	mouse_released(int btn, int x, int y, t_fdf *fdf)
{
	t_ctrl	*ctrl;

	(void)x;
	(void)y;
	ctrl = (t_ctrl *)&fdf->ctrl;
	if (btn == LEFT_CLICK)
		ctrl->rotate = false;
	if (btn == RIGHT_CLICK)
		ctrl->translate = false;
	fdf->evt_ctr = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	t_ctrl	*ctrl;

	ctrl = (t_ctrl *)&fdf->ctrl;
	if (ctrl->rotate)
		cam_rotate(fdf, x - ctrl->mouse_pos.x, y - ctrl->mouse_pos.y);
	if (ctrl->translate)
		cam_translate(fdf, x - ctrl->mouse_pos.x, y - ctrl->mouse_pos.y);
	// if (fdf->evt_ctr % 10 == 0)
	// 	draw_map(fdf);
	// fdf->evt_ctr++;
	return (0);
}
