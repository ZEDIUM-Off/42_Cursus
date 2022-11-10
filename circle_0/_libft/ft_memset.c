/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:31:35 by marvin            #+#    #+#             */
/*   Updated: 2022/11/10 11:15:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memset (void *s, int c, size_t n)
{
		unsigned char *ptr;
		size_t i;

		ptr = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
				ptr[i] = (unsigned char)c;
				i++;
		}	
		return (s); 
}