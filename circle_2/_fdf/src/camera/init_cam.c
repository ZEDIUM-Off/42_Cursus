/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:01:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/23 16:07:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_cam(t_fdf	*fdf)
{
	t_cam	*cam;

	cam = (t_cam *)&fdf->cam;
	cam->pos = (t_vec3){3.0, 3.0, 3.0};
	cam->target = (t_vec3){0.0, 0.0, 0.0};
	cam->dir = norm_vec3(sub_vec3s(cam->pos, cam->target));
	cam->right = norm_vec3(cross_product((t_vec3){0.0, 1.0, 0.0}, cam->dir));
	cam->up = cross_product(cam->dir, cam->right);
	cam->zoom = 45.0f;
	cam->speed = 0.0005f;
}
