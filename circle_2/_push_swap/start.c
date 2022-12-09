/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:56:24 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/09 13:50:21 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (LONG_MAX);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	parse_args(int argc, char **argv)
{
	long	test;

	argc--;
	while (argc)
	{
		test = ft_atoi(argv[argc]);
		if (test > INT_MAX || test < INT_MIN)
			return (0);
		argc--;
	}
	return (1);
}

int	*extract_values(int numbers, char **values)
{
	int	*values_int;
	int	i;

	values_int = malloc(sizeof(int) * numbers);
	if (!values_int)
		return (NULL);
	i = 0;
	while (i < numbers)
	{
		values_int[i] = ft_atoi(values[i]);
		i++;
	}
	return (values_int);
}
