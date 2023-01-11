/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_flag_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/12 10:51:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_on_flag_action(char flag, va_list args, int *len)
{
	if (flag == 'c')
		pf_putchar_fd(va_arg(args, int), 1, len);
	else if (flag == 's')
		pf_putstr_fd(va_arg(args, char *), 1, len);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", len, 1);
	else if (flag == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", len, 0);
	else if (flag == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", len, 0);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", len, 0);
	else if (flag == 'p')
	{
		pf_putstr_fd("0x", 1, len);
		ft_putnbr_base(
			va_arg(args, unsigned long long), "0123456789abcdef", len, 0);
	}
	else if (flag == '%')
		pf_putchar_fd('%', 1, len);
}
