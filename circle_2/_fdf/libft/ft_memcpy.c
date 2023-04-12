/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:16:32 by mchenava          #+#    #+#             */
/*   Updated: 2023/04/12 13:38:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		*ptr++ = *ptr2++;
	}
	return (dest);
}
