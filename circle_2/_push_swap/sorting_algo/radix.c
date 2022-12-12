/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:22:53 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/12 15:08:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_num;
	int	max_bits;
	int	size;
	int	current_num;
	int	i;
	int	j;

	max_num = (*stack_a)->size - 1;
	size = (*stack_a)->size;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (max_bits)
	{
		while (size)
		{
			current_num = (*stack_a)->top->value;
			if ((current_num >> size) & 1)
				rotate(stack_a, 1);
			else
				push(stack_b, stack_a, 1);
		}
		while ((*stack_b)->top != NULL)
			push(stack_a, stack_b, 1);
	}
}
