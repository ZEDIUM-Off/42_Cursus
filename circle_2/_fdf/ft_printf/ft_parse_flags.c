/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:08:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/13 14:27:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(int fd, const char *format, va_list args, int *len)
{
	int		i;

	i = 0;
	while (format[i] && *len >= 0)
	{
		if (format[i] == '%')
		{
			i++;
			ft_on_flag_action(fd, format[i], args, len);
		}
		else
			pf_putchar_fd(format[i], fd, len);
		i++;
	}
}
