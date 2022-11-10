/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:43:30 by mchenava            #+#    #+#             */
/*   Updated: 2022/11/10 10:58:22 by mchenava           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
		unsigned char *ptr;
		size_t i;

		ptr = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
				ptr[i] = (unsigned char)0;
				i++;
		}
}