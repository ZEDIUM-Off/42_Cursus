/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:36:53 by mchenava          #+#    #+#             */
/*   Updated: 2022/12/06 09:28:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *len)
{
	int	i;

	i = 0;
	if (fd < 0)
		*len = -1;
	if (s == NULL)
		ft_putstr_fd("(null)", fd, len);
	else
	{
		while (s[i])
		{
			if (write(fd, &s[i], 1) == -1)
				*len = -1;
			else
				*len += 1;
			i++;
		}
	}
}
