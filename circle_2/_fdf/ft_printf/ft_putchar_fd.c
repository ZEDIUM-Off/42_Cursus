/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:35:35 by mchenava          #+#    #+#             */
/*   Updated: 2022/12/12 10:48:26 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putchar_fd(char c, int fd, int *len)
{
	if (fd < 0)
		*len = -1;
	else if (write(fd, &c, 1) == -1)
		*len = -1;
	else
		*len += 1;
}
