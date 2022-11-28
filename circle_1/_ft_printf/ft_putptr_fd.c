/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:46:56 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/28 11:50:11 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	if (fd < 0)
		return (-1);
	if (ptr == 0)
		return (ft_putstr_fd("0x0", fd));
	if (ptr == NULL)
		return (ft_putnull_fd(fd));
	ft_putstr_fd("0x", fd);
	return (2 + ft_puthex_fd((unsigned long)ptr, fd, 0));
}
