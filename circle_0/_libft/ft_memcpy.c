/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:16:32 by marvin            #+#    #+#             */
/*   Updated: 2022/11/10 11:16:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
		unsigned char *ptr;
		size_t i;

		ptr = (unsigned char *)dest;
		i = 0;
		while (i < n)
		{
				ptr[i] = (unsigned char)src[i];
				i++;
		}
		return (dest);
}