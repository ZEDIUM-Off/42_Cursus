/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:11:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/10 15:58:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack **stack)
{
	unsigned int	i;
	t_node			*node;
	t_node			*min;

	min = (*stack)->top;
	node = (*stack)->top;
	i = 0;
	while (i < (*stack)->size)
	{
		if (node->value < min->value)
			min = node;
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
		rev_rotate(stack, 1);
	else if ((*stack)->top->value < (*stack)->top->next->value
		&& (*stack)->top->value < (*stack)->top->next->next->value)
	{
		if ((*stack)->top->next->value > (*stack)->top->next->next->value)
			rotate(stack, 1);
	}
}

void	sort_5(t_stack	**stack_a, t_stack	**stack_b)
{
	int			i;
	t_node		*min;

	i = 0;
	while (i < 2)
	{
		min = find_min(stack_a);
		if (min->position >= (int)(*stack_a)->size / 2)
			while ((*stack_a)->top->value != min->value)
				rev_rotate(stack_a, 1);
		else if (min->position < (int)(*stack_a)->size / 2)
			while ((*stack_a)->top->value != min->value)
				rotate(stack_a, 1);
		push(stack_b, stack_a, 1);
		i++;
	}
	sort(stack_a, stack_b);
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
	else if ((*stack_a)->size <= 5)
		while (!is_sorted(stack_a))
			sort_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
