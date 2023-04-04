/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_flag_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/13 14:32:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_on_flag_action(int fd, char flag, va_list args, int *len)
{
	if (flag == 'c')
		pf_putchar_fd(va_arg(args, int), fd, len);
	else if (flag == 's')
		pf_putstr_fd(va_arg(args, char *), fd, len);
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
		pf_putstr_fd("0x", fd, len);
		ft_putnbr_base(
			va_arg(args, unsigned long long), "0123456789abcdef", len, 0);
	}
	else if (flag == '%')
		pf_putchar_fd('%', fd, len);
}
