/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:56:24 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/12 10:33:31 by  mchenava        ###   ########.fr       */
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

int	find_duplicate(int numbers, int *values)
{
	int	i;
	int	j;

	i = 0;
	while (i < numbers)
	{
		j = i + 1;
		while (j < numbers)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv)
{
	long	test;
	int		i;

	if (argc == 1)
		argv = ft_split(argv[0], ' ');
	i = 0;
	while (i < argc)
	{
		test = ft_atoi(argv[i]);
		if (test > INT_MAX || test < INT_MIN)
			return (0);
		i++;
	}
	if (find_duplicate(argc, extract_values(argc, argv)))
		return (0);
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

void	init_a_b(t_stack **stack_a, t_stack **stack_b, int numbers, int *values)
{
	stack_init(numbers, values, "a", stack_a);
	stack_init(0, NULL, "b", stack_b);
	free(values);
}
