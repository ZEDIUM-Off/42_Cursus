/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:08:47 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/09 15:49:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(const char *format, va_list args, int *len)
{
	int		i;

	i = 0;
	while (format[i] && *len >= 0)
	{
		if (format[i] == '%')
		{
			i++;
			ft_on_flag_action(format[i], args, len);
		}
		else
			ft_putchar_fd(format[i], 1, len);
		i++;
	}
}
