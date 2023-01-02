/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:56:24 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 12:42:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	parse_args(int argc, char ***argv)
{
	long	test;
	int		i;
	int		size;
	int		*values;
	char	*char_values;

	i = 1;
	char_values = NULL;
	while (i < argc + 1)
		char_values = ft_strsepjoin(char_values, (*argv)[i++], ' ');
	size = ft_count_words(char_values, ' ');
	*argv = ft_split(char_values, ' ');
	free(char_values);
	i = 0;
	while (i < size)
	{
		test = ft_atoi((*argv)[i]);
		if (test > INT_MAX || test < INT_MIN)
			return (0);
		i++;
	}
	values = extract_values(size, (*argv));
	if (find_duplicate(size, values))
		return (free(values), 0);
	return (free(values), size);
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

t_stack_state	*init_a_b(
	t_stack **stack_a, t_stack **stack_b, int numbers, int *values)
{
	t_stack_state	*stacks;

	stack_init(numbers, values, "a", stack_a);
	stack_init(0, NULL, "b", stack_b);
	free(values);
	stacks = malloc(sizeof(t_stack_state));
	if (!stacks)
		return (NULL);
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	return (stacks);
}

void	act_position(t_stack **stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = (*stack)->top;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}
