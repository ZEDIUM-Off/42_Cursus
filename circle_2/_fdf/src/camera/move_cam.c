/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:42:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 14:35:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	cam_rotate(t_fdf *fdf, float delta_x, float delta_y)
{
	t_cam	*cam;
	float	yaw;
	float	pitch;
	t_vec3	cam2target;
	t_vec3	pos2origin;

	cam = (t_cam *)&fdf->cam;
	yaw = cam->speed * delta_x;
	pitch = cam->speed * delta_y;
	cam2target = sub_vec3s(cam->target, cam->pos);
	cam->dir = norm_vec3(cam2target);
	cam->dir = vec3_rotate(cam->dir, pitch, cam->right);
	cam->dir = vec3_rotate(cam->dir, yaw, (t_vec3){0, 1, 0});
	pos2origin = sub_vec3s(cam->pos, cam->target);
	pos2origin = vec3_rotate(pos2origin, yaw, (t_vec3){0, 1, 0});
	pos2origin = vec3_rotate(pos2origin, pitch, cam->right);
	cam->pos = add_vec3s(pos2origin, cam->target);
	cam->right = norm_vec3(cross_product(cam->dir, (t_vec3){0, 1, 0}));
	cam->up = cross_product(cam->right, cam->dir);
}

void	cam_translate(t_fdf *fdf, int x_offset, int y_offset)
{
	t_cam		*cam;
	t_vec3		translation;

	cam = &fdf->cam;
	translation = add_vec3s(
			scale_vec3s(norm_vec3(cam->right), -x_offset * cam->speed / 10),
			scale_vec3s(norm_vec3(cam->up), y_offset * cam->speed / 10));
	cam->pos = add_vec3s(cam->pos, translation);
	cam->target = add_vec3s(cam->target, translation);
}
