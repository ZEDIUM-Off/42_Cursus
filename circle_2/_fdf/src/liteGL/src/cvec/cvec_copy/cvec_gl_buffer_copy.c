/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_gl_buffer_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:45:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 16:46:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copyc_t_gl_buffer(void *dest, void *src)
{
	cvector_t_gl_buffer	*vec1;
	cvector_t_gl_buffer	*vec2;

	vec1 = (cvector_t_gl_buffer *)dest;
	vec2 = (cvector_t_gl_buffer *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_t_gl_buffer(vec1, vec2));
}

int	cvec_copy_t_gl_buffer(cvector_t_gl_buffer	*dest, cvector_t_gl_buffer *src)
{
	t_gl_buffer	*tmp;

	tmp = (t_gl_buffer *)ft_realloc(
			dest->a, src->capacity * sizeof(t_gl_buffer));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(t_gl_buffer));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}
