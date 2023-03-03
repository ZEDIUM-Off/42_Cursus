/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_gl_buffer_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:49:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 16:53:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_buffer	cvec_replace_t_gl_buffer(
	cvector_t_gl_buffer *vec, size_t i, t_gl_buffer a)
{
	t_gl_buffer	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_t_gl_buffer(
	cvector_t_gl_buffer	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(t_gl_buffer));
	vec->size -= d;
}

int	cvec_reserve_t_gl_buffer(cvector_t_gl_buffer *vec, size_t size)
{
	t_gl_buffer	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_gl_buffer *)ft_realloc(
				vec->a, sizeof(t_gl_buffer) * (size + CVEC_t_gl_buffer_SZ));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_t_gl_buffer_SZ;
	}
	return (1);
}

t_gl_buffer	*cvec_back_t_gl_buffer(cvector_t_gl_buffer *vec)
{
	return (&vec->a[vec->size - 1]);
}
