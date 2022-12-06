/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_flag_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/06 11:23:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_on_flag_action(char flag, va_list args, int *len)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(args, int), 1, len);
	else if (flag == 's')
		ft_putstr_fd(va_arg(args, char *), 1, len);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", len, 1);
	else if (flag == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", len, 0);
	else if (flag == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", len, 0);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", len, 0);
	else if (flag == 'p')
		ft_putptr(va_arg(args, unsigned long long), len);
	else if (flag == '%')
		ft_putchar_fd('%', 1, len);
}
