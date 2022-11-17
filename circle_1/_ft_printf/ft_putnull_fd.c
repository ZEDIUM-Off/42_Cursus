/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnull_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:26:53 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/17 10:53:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnull_fd(int fd)
{
	if (fd < 0)
		return (-1);
	return (ft_putstr_fd("(null)", fd));
}
