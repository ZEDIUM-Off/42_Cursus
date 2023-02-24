/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/24 14:49:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_DRAW_H
# define GL_DRAW_H

# include <lite_gd.h>

void	triangle_mode(GLint first, GLsizei count);
void	line_mode(GLint first, GLsizei count);
void	point_mode(GLint first, GLsizei count);
void	triangle_fan_mode(GLsizei count);
void	triangle_strip_mode(GLsizei count);
void	line_loop_mode(GLint first, GLsizei count);
void	line_strip_mode(GLint first, GLsizei count);
void	run_pipeline(GLenum mode, GLint first, GLsizei count);
void	gl_draw_arrays(GLenum mode, GLint first, GLsizei count);

#endif
