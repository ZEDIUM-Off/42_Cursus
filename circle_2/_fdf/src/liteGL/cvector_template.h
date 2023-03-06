/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector_template.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:03:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 16:46:40 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVECTOR_TEMPLATE_H
# define CVECTOR_TYPE_H

typedef struct cvector_TYPE
{
	TYPE	*a;
	size_t	size;
	size_t	capacity;
}	t_cvector_TYPE;

int				cvec_TYPE(cvector_TYPE *vec, size_t size, size_t capacity);
int				cvec_init_TYPE(cvector_TYPE *vec, TYPE *vals, size_t num);

cvector_TYPE	*cvec_TYPE_heap(size_t size, size_t capacity);
cvector_TYPE	*cvec_init_TYPE_heap(TYPE *vals, size_t num);
int				cvec_copyc_TYPE(void *dest, void *src);
int				cvec_copy_TYPE(cvector_TYPE *dest, cvector_TYPE *src);

int				cvec_push_TYPE(cvector_TYPE *vec, TYPE a);
TYPE			cvec_pop_TYPE(cvector_TYPE *vec);

int				cvec_extend_TYPE(cvector_TYPE *vec, size_t num);
int				cvec_insert_TYPE(cvector_TYPE *vec, size_t i, TYPE a);
int				cvec_insert_array_TYPE(
					cvector_TYPE *vec, size_t i, TYPE *a, size_t num);
TYPE			cvec_replace_TYPE(cvector_TYPE *vec, size_t i, TYPE a);
void			cvec_erase_TYPE(cvector_TYPE *vec, size_t start, size_t end);
int				cvec_reserve_TYPE(cvector_TYPE *vec, size_t size);
int				cvec_set_cap_TYPE(cvector_TYPE *vec, size_t size);
void			cvec_set_val_sz_TYPE(cvector_TYPE *vec, TYPE val);
void			cvec_set_val_cap_TYPE(cvector_TYPE *vec, TYPE val);

TYPE			*cvec_back_TYPE(cvector_TYPE *vec);

void			cvec_clear_TYPE(cvector_TYPE *vec);
void			cvec_free_TYPE_heap(void *vec);
void			cvec_free_TYPE(void	*vec);

/* CVECTOR_TYPE_H */
#endif

cvector_TYPE	*cvec_TYPE_heap(size_t size, size_t capacity)
{
	cvector_TYPE	*vec;

	vec = (cvector_TYPE *)malloc(sizeof(cvector_TYPE));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->size = size;
	vec->capacity = vec->size + CVEC_TYPE_SZ;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (TYPE *)malloc(vec->capacity * sizeof(TYPE));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	return (vec);
}

cvector_TYPE	*cvec_init_TYPE_heap(TYPE *vals, size_t num)
{
	cvector_TYPE	*vec;

	vec = (cvector_TYPE *)malloc(sizeof(cvector_TYPE));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_TYPE_SZ;
	vec->size = num;
	vec->a = (TYPE *)malloc(vec->capacity * sizeof(TYPE));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(TYPE) * num);
	return (vec);
}

int	cvec_TYPE(cvector_TYPE *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_TYPE_SZ;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (TYPE *)malloc(vec->capacity * sizeof(TYPE));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_TYPE(cvector_TYPE *vec, TYPE *vals, size_t num)
{
	vec->capacity = num + CVEC_TYPE_SZ;
	vec->size = num;
	vec->a = (TYPE *)malloc(vec->capacity * sizeof(TYPE));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(TYPE) * num);
	return (1);
}

int	cvec_copyc_TYPE(void *dest, void *src)
{
	cvector_TYPE	*vec1;
	cvector_TYPE	*vec2;

	vec1 = (cvector_TYPE *)dest;
	vec2 = (cvector_TYPE *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_TYPE(vec1, vec2));
}

int	cvec_copy_TYPE(cvector_TYPE	*dest, cvector_TYPE *src)
{
	TYPE	*tmp;

	tmp = (TYPE *)ft_realloc(dest->a, src->capacity * sizeof(TYPE));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(TYPE));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}

int	cvec_push_TYPE(cvector_TYPE *vec, TYPE a)
{
	TYPE	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (TYPE *)ft_realloc(vec->a, sizeof(TYPE) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->a[vec->size++] = a;
		vec->capacity = tmp_sz;
	}
	return (1);
}

TYPE	cvec_pop_TYPE(cvector_TYPE *vec)
{
	return (vec->a[--vec->size]);
}

TYPE	*cvec_back_TYPE(cvector_TYPE *vec)
{
	return (&vec->a[vec->size - 1]);
}

int	cvec_extend_TYPE(cvector_TYPE *vec, size_t num)
{
	TYPE	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_TYPE_SZ;
		tmp = (TYPE *)ft_realloc(vec->a, sizeof(TYPE) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	vec->size += num;
	return (1);
}

int	cvec_insert_TYPE(cvector_TYPE *vec, size_t i, TYPE a)
{
	TYPE	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], &vec->a[i], (vec->size - i) * sizeof(TYPE));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (TYPE *)ft_realloc(vec->a, sizeof(TYPE) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i], (vec->size - i) * sizeof(TYPE));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_TYPE(cvector_TYPE *vec, size_t i, TYPE *a, size_t num)
{
	TYPE	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_TYPE_SZ;
		tmp = (TYPE *)ft_realloc(vec->a, sizeof(TYPE) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + num], &vec->a[i], (vec->size - i) * sizeof(TYPE));
	ft_memmove(&vec->a[i], a, num * sizeof(TYPE));
	vec->size += num;
	return (1);
}

TYPE	cvec_replace_TYPE(cvector_TYPE *vec, size_t i, TYPE a)
{
	TYPE	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_TYPE(cvector_TYPE	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1], (vec->size - 1 - end) * sizeof(TYPE));
	vec->size -= d;
}

int	cvec_reserve_TYPE(cvector_TYPE *vec, size_t size)
{
	TYPE	*tmp;

	if (vec->capacity < size)
	{
		tmp = (TYPE *)ft_realloc(vec->a, sizeof(TYPE) * (size + CVEC_TYPE_SZ));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_TYPE_SZ;
	}
	return (1);
}

int	cvec_set_cap_TYPE(cvector_TYPE *vec, size_t size)
{
	TYPE	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (TYPE *)ft_realloc(vec->a, sizeof(TYPE) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_TYPE(cvector_TYPE *vec, TYPE val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_TYPE(cvector_TYPE *vec, TYPE val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}

void	cvec_clear_TYPE(cvector_TYPE *vec)
{
	vec->size = 0;
}

void	cvec_free_TYPE_heap(void *vec)
{
	cvector_TYPE	*tmp;

	tmp = (cvector_TYPE *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_TYPE(void *vec)
{
	cvector_TYPE	*tmp;

	tmp = (cvector_TYPE *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}

#endif
