/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:46:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/05 11:42:11 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t newsize)
{
	void	*newptr;

	if (!ptr)
		return (ft_calloc(newsize, 1));
	newptr = ft_calloc(newsize, 1);
	if (!newptr)
		return (NULL);
	ft_memcpy(newptr, ptr, newsize);
	free(ptr);
	return (newptr);
}
