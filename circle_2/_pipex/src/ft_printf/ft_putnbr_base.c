/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:48:30 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/12 10:52:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long nbr, char *base, int *len, int _signed)
{
	unsigned long long	nb;

	if (nbr < 0 && _signed)
	{
		nb = -nbr;
		pf_putchar_fd('-', 1, len);
	}
	else
		nb = nbr;
	if (nb >= (unsigned int)ft_strlen(base))
		ft_putnbr_base(nb / ft_strlen(base), base, len, _signed);
	pf_putchar_fd(base[nb % ft_strlen(base)], 1, len);
}
