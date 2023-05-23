/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:04:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/12 12:02:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	vertex_shader(
	float	*vs_output, void *vertex_attribs,
	t_shader_builtins *builtins, void *uniforms)
{
	t_fdf_uniforms	*u;
	t_vec4			*v_attribs;

	u = uniforms;
	v_attribs = vertex_attribs;
	builtins->gl_position = mult_mat4_vec4(u->mvp_mat, v_attribs[0]);
	vs_output[0] = v_attribs[0].y;
	// printf ("vs_output[0] = %f\n", vs_output[0]);
}

void	fragment_shader(
	float *fs_input, t_shader_builtins *builtins, void *uniforms)
{
	float			norm_alt;
	float			vert_alt;
	t_vec4			color1;
	t_vec4			color2;

	(void)uniforms;
	vert_alt = fs_input[0];
	norm_alt = (vert_alt + 1) / 2;
	color1 = (t_vec4){0.0, 0.0, 1.0, 1.0};
	color2 = (t_vec4){1.0, 0.0, 0.0, 1.0};
	builtins->gl_frag_color.x = color1.x * (1 - norm_alt) + color2.x * norm_alt;
	builtins->gl_frag_color.y = color1.y * (1 - norm_alt) + color2.y * norm_alt;
	builtins->gl_frag_color.z = color1.z * (1 - norm_alt) + color2.z * norm_alt;
	builtins->gl_frag_color.w = 1;
}

void	fdf_shader_init(t_fdf *fdf)
{
	t_gl_uint		shader;
	t_gl_program	prog_attr;
	t_gl_enum		interp[1];

	prog_attr = (t_gl_program){
		.vertex_shader = vertex_shader, .fragment_shader = fragment_shader,
		.vs_output_size = 1, .fragdepth_or_discard = GL_FALSE
	};
	interp[0] = SMOOTH;
	shader = lgl_create_program(&fdf->glx, prog_attr, interp);
	gl_use_program(&fdf->glx, shader);
	lgl_set_uniform(&fdf->glx, &fdf->uniforms);
	fdf->uniforms.project = cam_proj;
	printf("shader initialized\n");
}
