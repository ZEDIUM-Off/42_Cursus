/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:41:52 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/17 10:39:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned long long n, int fd, int upper)
{
	char	c;

	if (fd < 0)
		return (-1);
	if (n >= 16)
		ft_puthex_fd(n / 16, fd, upper);
	c = n % 16 + '0';
	if (c > '9')
		c += 39;
	if (upper)
		ft_putchar_fd(ft_toupper(c), fd);
	else
		ft_putchar_fd(c, fd);
	return (ft_hexlen(n));
}
