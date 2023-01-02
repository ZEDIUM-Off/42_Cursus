/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:22:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/02 11:02:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack_state *stacks)
{
	int		size;
	int		top;
	int		i;

	i = 0;
	while (!is_sorted(stacks->stack_a))
	{
		size = (*stacks->stack_a)->size;
		while (size)
		{
			top = (*stacks->stack_a)->top->value;
			if ((top >> i) & 1)
				rotate(stacks->stack_a, 1);
			else
				push(stacks->stack_b, stacks->stack_a, 1);
			size--;
		}
		while ((*stacks->stack_b)->top != NULL)
			push(stacks->stack_a, stacks->stack_b, 1);
		i++;
	}
}
