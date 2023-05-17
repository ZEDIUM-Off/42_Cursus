/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/17 13:12:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_pressed(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		quit_fdf(fdf);
	if (key == XK_p)
		switch_proj(fdf);
	if (key == XK_d)
		switch_draw(fdf);
	return (0);
}
