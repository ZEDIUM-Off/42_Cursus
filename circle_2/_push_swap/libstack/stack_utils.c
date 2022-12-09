/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:49:44 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/09 17:19:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	display_stack(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 0;
	ft_printf("======== stack %s : ==========\n", stack->name);
	while ((unsigned int)i < stack->size)
	{
		ft_printf("Valeur n.%d = %d \n", node->position, node->value);
		node = node->next;
		i++;
	}
}

t_stack	*new_stack(int size, char *name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->name = name;
	stack->size = size;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*new_node(int value, int position)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->position = position;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*stack_init(int size, int *values, char *name)
{
	t_stack	*stack;
	t_node	*node;
	t_node	*tmp;
	int		i;

	stack = new_stack(size, name);
	i = size - 1;
	while (i >= 0 && values != NULL)
	{
		node = new_node(values[i], i);
		if (stack->top == NULL)
		{
			stack->top = node;
			stack->bottom = node;
		}
		else
		{
			tmp = stack->top;
			stack->top = node;
			stack->top->next = tmp;
			tmp->prev = stack->top;
		}
		i--;
	}
	return (stack);
}

void	stack_clear(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}
