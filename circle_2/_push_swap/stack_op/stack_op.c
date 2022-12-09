/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:06 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/09 17:14:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int disp_op)
{
	t_node	*tmp;
	int		tmp_pos;

	if ((*stack)->size > 1)
	{
		tmp = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		tmp->next = (*stack)->top->next;
		(*stack)->top->next = tmp;
		tmp_pos = (*stack)->top->position;
		(*stack)->top->position = tmp->position;
		tmp->position = tmp_pos;
	}
	if (disp_op)
		ft_printf("s%s\n", (*stack)->name);
}

void	push(t_stack **stack_in, t_stack **stack_out, int disp_op)
{
	t_node	*tmp;

	if ((*stack_out)->size > 0)
	{
		tmp = (*stack_out)->top;
		(*stack_out)->top = (*stack_out)->top->next;
		(*stack_out)->size--;
		tmp->next = (*stack_in)->top;
		(*stack_in)->top = tmp;
		(*stack_in)->size++;
	}
	if (disp_op)
		ft_printf("p%s\n", (*stack_in)->name);
}

void	rotate(t_stack **stack, int disp_op)
{
	t_node	*tmp;

	if ((*stack)->size > 1)
	{
		tmp = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		tmp->next = NULL;
		(*stack)->bottom->next = tmp;
		(*stack)->bottom = tmp;
	}
	if (disp_op)
		ft_printf("r%s\n", (*stack)->name);
}

void	rev_rotate(t_stack **stack, int disp_op)
{
	t_node	*tmp;

	if ((*stack)->size > 1)
	{
		tmp = (*stack)->top;
		while (tmp->next->next)
			tmp = tmp->next;
		(*stack)->bottom = tmp->next;
		tmp->next = NULL;
		(*stack)->bottom->next = (*stack)->top;
		(*stack)->top = (*stack)->bottom;
	}
	if (disp_op)
		ft_printf("rr%s\n", (*stack)->name);
}

void	both(
	t_stack **stack_1,
	t_stack **stack_2,
	void (*op)(t_stack **, int),
	char *str
)
{
	op(stack_1, 0);
	op(stack_2, 0);
	ft_printf("%s", str);
}
