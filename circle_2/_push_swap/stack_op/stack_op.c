/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/10 14:11:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int disp_op)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if ((*stack)->size > 1)
	{
		tmp1 = (*stack)->top;
		tmp2 = (*stack)->top->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		(*stack)->top = tmp2;
		act_position(stack);
		if (disp_op && ft_strncmp((*stack)->name, "a", 5) == 0)
			ft_printf("sa\n");
		else if (disp_op && ft_strncmp((*stack)->name, "b", 5) == 0)
			ft_printf("sb\n");
	}
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
		act_position(stack_in);
		act_position(stack_out);
		if (disp_op && ft_strncmp((*stack_in)->name, "a", 5) == 0)
			ft_printf("pa\n");
		else if (disp_op && ft_strncmp((*stack_in)->name, "b", 5) == 0)
			ft_printf("pb\n");
	}
}

void	rotate(t_stack **stack, int disp_op)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if ((*stack)->size > 1)
	{
		tmp1 = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		tmp1->next = NULL;
		tmp2 = get_node(stack, (*stack)->size - 1);
		tmp2->next = tmp1;
		act_position(stack);
		if (disp_op && ft_strncmp((*stack)->name, "a", 5) == 0)
			ft_printf("ra\n");
		else if (disp_op && ft_strncmp((*stack)->name, "b", 5) == 0)
			ft_printf("rb\n");
	}
}

void	rev_rotate(t_stack **stack, int disp_op)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stack)->size > 1)
	{
		tmp = get_node(stack, (*stack)->size - 1);
		tmp2 = get_node(stack, (*stack)->size - 2);
		tmp->next = (*stack)->top;
		(*stack)->top = tmp;
		tmp2->next = NULL;
		act_position(stack);
		if (disp_op && ft_strncmp((*stack)->name, "a", 5) == 0)
			ft_printf("rra\n");
		else if (disp_op && ft_strncmp((*stack)->name, "b", 5) == 0)
			ft_printf("rrb\n");
	}
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
