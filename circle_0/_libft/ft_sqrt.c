/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:48:57 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/15 09:56:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	start;
	size_t	end;
	size_t	mid;
	size_t	sqr;

	if (nb < 2)
		return (nb);
	start = 1;
	end = nb / 2;
	while (start <= end)
	{
		mid = (start + end) / 2;
		sqr = mid * mid;
		if (sqr == nb)
			return (mid);
		else if (sqr < nb)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}