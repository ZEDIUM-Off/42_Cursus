/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:11:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/09 16:58:02 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack **stack)
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
	return (min);
}

void	sort_3(t_stack **stack)
{
	if ((*stack)->top->value > (*stack)->top->next->value
		&& (*stack)->top->value > (*stack)->top->next->next->value)
	{
		if ((*stack)->top->next->value > (*stack)->top->next->next->value)
			rotate(stack, 1);
		else
			rev_rotate(stack, 1);
	}
	else if ((*stack)->top->value > (*stack)->top->next->value
		&& (*stack)->top->value < (*stack)->top->next->next->value)
		swap(stack, 1);
	else if ((*stack)->top->value < (*stack)->top->next->value
		&& (*stack)->top->value > (*stack)->top->next->next->value)
	{
		swap(stack, 1);
		rev_rotate(stack, 1);
	}
	else if ((*stack)->top->value < (*stack)->top->next->value
		&& (*stack)->top->value < (*stack)->top->next->next->value)
	{
		if ((*stack)->top->next->value > (*stack)->top->next->next->value)
			rotate(stack, 1);
	}
}

void	sort_5(t_stack	**stack_a, t_stack	**stack_b)
{
	int		i;
	int		min;

	i = 0;
	while (i < 2)
	{
		min = find_min(stack_a);
		while ((*stack_a)->top->value != min)
			rotate(stack_a, 1);
		push(stack_b, stack_a, 1);
		i++;
	}
	sort_3(stack_a);
	push(stack_a, stack_b, 1);
	push(stack_a, stack_b, 1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size == 2
		&& (*stack_a)->top->value > (*stack_a)->top->next->value)
		swap(stack_a, 1);
	else if ((*stack_a)->size == 3)
		while (!is_sorted(stack_a))
			sort_3(stack_a);
	else if ((*stack_a)->size <= 5 && !is_sorted(stack_a))
		while (!is_sorted(stack_a))
			sort_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
