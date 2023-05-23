/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:49:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/12 14:15:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*get_node(t_stack **stack, int position)
{
	t_node	*node;

	node = (*stack)->top;
	while (node != NULL)
	{
		if (node->position == position)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_stack	*new_stack(int size, char *name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->name = name;
	stack->size = size;
	stack->top = NULL;
	return (stack);
}

t_node	*new_node(int value, int position)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->position = position;
	node->next = NULL;
	return (node);
}

void	stack_init(int size, int *values, char *name, t_stack	**stack)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	(*stack) = new_stack(size, name);
	i = size - 1;
	while (i >= 0 && values != NULL)
	{
		node = new_node(values[i], i);
		if ((*stack)->top == NULL)
			(*stack)->top = node;
		else
		{
			tmp = (*stack)->top;
			(*stack)->top = node;
			(*stack)->top->next = tmp;
		}
		i--;
	}
}

void	stack_clear(t_stack **stack)
{
	t_node	*node;
	t_node	*tmp;

	node = (*stack)->top;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free((*stack));
}
