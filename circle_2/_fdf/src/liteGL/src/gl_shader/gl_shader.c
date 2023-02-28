/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_shader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:35:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 10:00:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_interpol(glProgram	*prog, t_gl_sizei n, GLenum *interpolation)
{
	int	i;

	i = 0;
	while (i < n)
	{
		prog->interpolation[i] = interpolation[i];
		i++;
	}
}

void	lgl_set_uniform(t_GLContext *c, void *uniform)
{
	c->programs.a[c->cur_program].uniform = uniform;
}

GLuint	lgl_create_program(t_GLContext *c, glProgram prog_attr)
{
	glProgram	tmp;
	int			i;

	if (!prog_attr.vertex_shader || !prog_attr.fragment_shader)
		return (0);
	if (prog_attr.vs_output_size > GL_MAX_VERTEX_OUTPUT_COMPONENTS)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return (0);
	}
	tmp = {prog_attr.vertex_shader, prog_attr.fragment_shader, NULL, \
	prog_attr.vs_output_size, {0}, prog_attr.fragdepth_or_discard, GL_FALSE};
	set_interpol(&tmp, prog_attr.vs_output_size, prog_attr.interpolation);
	i = 1;
	while (i < c->programs.sizei)
	{
		if (c->programs.a[i].deleted && i != c->cur_program)
		{
			c->programs.a[i] = tmp;
			return (i);
		}
		i++;
	}
	return (cvec_push_glProgram(&c->programs, tmp), c->programs.size - 1);
}

void	gl_use_program(t_GLContext *c, GLuint program)
{
	if (program >= c->programs.size)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->vs_output.size = c->programs.a[program].vs_output_size;
	cvec_reserve_float(&c->vs_output.output_buf,
		c->vs_output.size * MAX_VERTICES);
	c->vs_output.interpolation = c->programs.a[program].interpolation;
	c->fragdepth_or_discard = c->programs.a[program].fragdepth_or_discard;
	c->cur_program = program;
}

void	gl_delete_program(t_ GLContext *c, GLuint program)
{
	if (!program)
		return ;
	if (program >= c->programs.size)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->programs.a[program].deleted = GL_TRUE;
}
