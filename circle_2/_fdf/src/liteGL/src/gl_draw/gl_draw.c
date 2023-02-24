/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:17:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/24 14:00:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	run_pipeline(GLenum mode, GLint first, GLsizei count)
{
	int	i;
	int	vert;
	int	provoke;

	vertex_stage(first, count);
	if (mode == GL_POINTS)
		point_mode(first, count);
	else if (mode == GL_LINES)
		line_mode(first, count);
	else if (mode == GL_LINE_STRIP)
		line_strip_mode(first, count);
	else if (mode == GL_LINE_LOOP)
		line_loop_mode(first, count);
	else if (mode == GL_TRIANGLES)
		triangle_mode(first, count);
	else if (mode == GL_TRIANGLE_STRIP)
		triangle_strip_mode(count);
	else if (mode == GL_TRIANGLE_FAN)
		triangle_fan_mode(count);
}

void	gl_draw_arrays(GLenum mode, GLint first, GLsizei count)
{
	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (count < 0)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	if (!count)
		return ;
	run_pipeline(mode, first, count);
}
