/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_gl_buffer_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:55:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 16:55:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_t_gl_buffer(cvector_t_gl_buffer *vec)
{
	vec->size = 0;
}

void	cvec_free_t_gl_buffer_heap(void *vec)
{
	cvector_t_gl_buffer	*tmp;

	tmp = (cvector_t_gl_buffer *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_t_gl_buffer(void *vec)
{
	cvector_t_gl_buffer	*tmp;

	tmp = (cvector_t_gl_buffer *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
