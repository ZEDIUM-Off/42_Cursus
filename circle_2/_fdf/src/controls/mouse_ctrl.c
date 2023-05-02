/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:27:31 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/02 17:06:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mouse_pressed(int btn, int x, int y, t_fdf *fdf)
{
	t_ctrl	*ctrl;

	ctrl = (t_ctrl *)&fdf->ctrl;
	if (btn == LEFT_CLICK)
	{
		ctrl->rotate = true;
		ctrl->mouse_pos = (t_vec2){x, y};
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
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	t_ctrl	*ctrl;

	ctrl = (t_ctrl *)&fdf->ctrl;
	if (ctrl->rotate)
	{
		cam_rotate(fdf, x - ctrl->mouse_pos.x, y - ctrl->mouse_pos.y);
		draw_map(fdf);
	}
	return (0);
}
