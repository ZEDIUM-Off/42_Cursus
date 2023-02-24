/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:03:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/22 14:13:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib3d.h>

t_vec3	*get_cam_forward(t_camera *cam)
{
	return (vec3_norm(vec3_sub(cam->target, cam->pos)));
}

t_vec3	*get_cam_up(t_camera *cam)
{
	return (vec3_norm(cam->up));
}

t_vec3	*get_cam_right(t_camera *cam)
{
	t_vec3	*forward;
	t_vec3	*up;
	t_vec3	*right;

	forward = get_cam_forward(cam);
	up = get_cam_up(cam);
	right = vec3_cross(forward, up);
	free(forward);
	free(up);
	return (right);
}

t_mat4	get_view_mat(t_camera *cam)
{
	return (look_at(cam->pos, cam->target, cam->up));
}

t_mat4	get_proj_mat(t_camera *cam, float aspect)
{
	float	top;
	float	right;

	if (cam->proj == PERSECTIVE)
		return (mat4_perspective(cam->fov * (M_PI / 180.0f), aspect,
				CAM_NEAR, CAM_FAR));
	else if (cam->proj == ORTHOGRAPHIC)
	{
		top = cam->fovy / 2.0f;
		right = top * aspect;
		return (mat4_ortho(-right, right, -top, top, CAM_NEAR, CAM_FAR));
	}
	return (mat4_identity());
}
