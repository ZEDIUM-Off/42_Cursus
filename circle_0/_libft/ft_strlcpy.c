/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:15:25 by mchenava            #+#    #+#             */
/*   Updated: 2022/11/10 16:24:42 by mchenava           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
		size_t i;

		i = 0;
		if (size == 0)
				return (ft_strlen(src));
		while (i < size - 1 && src[i] != '\0')
		{
				dst[i] = src[i];
				i++;
		}
		dst[i] = '\0';
		return (ft_strlen(src));
}