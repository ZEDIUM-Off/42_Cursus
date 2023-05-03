/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:47:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 11:33:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_window(t_fdf *fdf)
{
	fdf->mxv.mlx = mlx_init();
	fdf->mxv.win = mlx_new_window(fdf->mxv.mlx, WIDTH, HEIGHT, "fdf");
	fdf->mxv.img = mlx_new_image(fdf->mxv.mlx, WIDTH, HEIGHT);
}
