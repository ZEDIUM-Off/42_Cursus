/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:46:56 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/06 11:36:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putptr(unsigned long long n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putstr_fd("(null)", 1, len);
		return ;
	}
	ft_putstr_fd("0x", 1, len);
	ft_putnbr_base(n, base, len, 0);
}
