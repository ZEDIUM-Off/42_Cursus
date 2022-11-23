/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:36:53 by mchenava          #+#    #+#             */
/*   Updated: 2022/11/23 12:08:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return (-1);
	if (s == NULL)
		return (ft_putnull_fd(fd));
	i = 0;
	while (s[i])
		i++;
	return (write(fd, s, i));
}
