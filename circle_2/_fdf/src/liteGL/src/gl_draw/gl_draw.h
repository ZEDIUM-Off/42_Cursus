/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/27 15:39:29 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_DRAW_H
# define GL_DRAW_H

# include <lite_gd.h>

void	triangle_mode(t_gl_int first, t_gl_sizei count);
void	line_mode(t_gl_int first, t_gl_sizei count);
void	point_mode(t_gl_int first, t_gl_sizei count);
void	triangle_fan_mode(t_gl_sizei count);
void	triangle_strip_mode(t_gl_sizei count);
void	line_loop_mode(t_gl_int first, t_gl_sizei count);
void	line_strip_mode(t_gl_int first, t_gl_sizei count);
void	run_pipeline(t_gl_enum mode, t_gl_int first, t_gl_sizei count);
void	gl_draw_arrays(t_gl_enum mode, t_gl_int first, t_gl_sizei count);

#endif
