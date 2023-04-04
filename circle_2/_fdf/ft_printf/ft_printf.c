/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:01:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/13 14:27:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	ft_parse_flags(fd, format, args, &len);
	va_end(args);
	return (len);
}
