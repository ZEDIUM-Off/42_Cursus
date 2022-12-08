/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:49:44 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/08 10:15:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

void	display_stack(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 0;
	while ((unsigned int)i < stack->size)
	{
		printf("%d ", node->value);
		node = node->next;
		i++;
	}
}

t_stack	*stack_init(int size, int *values)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->top = NULL;
	i = size;
	while (i > 0)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return (NULL);
		node->value = values[i - 1];
		node->next = stack->top;
		stack->top = node;
		i--;
	}
	return (stack);
}
