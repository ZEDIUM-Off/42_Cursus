/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:14:11 by mchenava            #+#    #+#             */
/*   Updated: 2022/11/10 16:15:07 by mchenava           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (ptr2 < ptr)
	{
		while (n--)
		{
			ptr[n] = ptr2[n];
		}
	}
	else
	{
		while (n--)
		{
			*ptr++ = *ptr2++;
		}
	}
	return (dest);
}