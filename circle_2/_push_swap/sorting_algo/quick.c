/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:53:07 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 15:14:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(
	t_stack_state	*stacks,
	int low,
	int high,
	char	**ops
)
{
	int	pivot;
	int	i;
	int	j;

	pivot = get_node(stacks->stack_a, high)->value;
	i = low - 1;
	j = low;
	while (j <= high)
	{
		display_stack((*stacks->stack_a));
		display_stack((*stacks->stack_b));
		if (get_node(stacks->stack_a, j)->value < pivot)
		{
			i++;
			*ops = ft_strjoin(*ops, swap_values(stacks, i, j));
		}
		j++;
	}
	*ops = ft_strjoin(*ops, swap_values(stacks, i + 1, high));
	return (i + 1);
}

char	*quick_sort(t_stack_state	*stacks, int low, int high)
{
	int		pivot;
	char	*ops;

	ops = NULL;
	if (low < high)
	{
		pivot = partition(stacks, low, high, &ops);
		ops = ft_strjoin(ops, quick_sort(stacks, low, pivot - 1));
		ops = ft_strjoin(ops, quick_sort(stacks, pivot + 1, high));
	}
	return (ops);
}

char	*quick(t_stack_state	*stacks)
{
	char	*ops;
	int		size;

	size = (*stacks->stack_a)->size;
	ops = quick_sort(stacks, 0, size - 1);
	return (ops);
}
