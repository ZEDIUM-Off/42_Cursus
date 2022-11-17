/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_flag_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/17 10:18:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_on_flag_action(char flag, va_list args)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (flag == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (flag == 'd' || flag == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (flag == 'u')
		len += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (flag == 'x')
		len += ft_puthex_fd(va_arg(args, unsigned int), 1, 0);
	else if (flag == 'X')
		len += ft_puthex_fd(va_arg(args, unsigned int), 1, 1);
	else if (flag == 'p')
		len += ft_putptr_fd(va_arg(args, void *), 1);
	else if (flag == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}
