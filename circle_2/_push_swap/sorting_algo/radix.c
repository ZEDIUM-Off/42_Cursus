/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:22:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/10 13:20:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplify(t_stack **stack)
{
	int				min;
	unsigned int	i;
	t_node			*node;

	min = (*stack)->top->value;
	node = (*stack)->top;
	i = 0;
	while (i < (*stack)->size)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
		i++;
	}
	node = (*stack)->top;
	i = 0;
	while (i < (*stack)->size)
	{
		node->value -= min;
		node = node->next;
		i++;
	}
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		top;
	int		i;

	i = 0;
	simplify(stack_a);
	while (!is_sorted(stack_a))
	{
		size = (*stack_a)->size;
		while (size)
		{
			top = (*stack_a)->top->value;
			if ((top >> i) & 1)
				rotate(stack_a, 1);
			else
				push(stack_b, stack_a, 1);
			size--;
		}
		while ((*stack_b)->top != NULL)
			push(stack_a, stack_b, 1);
		i++;
	}
}
