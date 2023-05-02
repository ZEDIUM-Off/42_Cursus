/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:42:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/02 15:36:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	cam_rotate(t_fdf *fdf, float delta_x, float delta_y)
{
	t_cam	*cam;

	cam = (t_cam *)&fdf->cam;
	(void)delta_x; (void)delta_y;
	cam->pos = add_vec3s(cam->pos, scale_vec3s(norm_vec3(cross_product(cam->dir, cam->up)), cam->speed));
	printf("cam pos : x = %f, y = %f z = %f\n", cam->pos.x, cam->pos.y, cam->pos.z);
	cam->dir = norm_vec3(sub_vec3s(cam->pos, cam->target));
}
