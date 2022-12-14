/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:59:41 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 14:59:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_values(t_stack_state	*stacks, int i, int j)
{
	char	*ops;
	t_node	*tmpi;
	t_node	*tmpj;
	t_node	*tmp_top;

	ops = NULL;
	if (i == j)
		return (NULL);
	if (i > j)
		return (swap_values(stacks, j, i));
	tmp_top = (*stacks->stack_a)->top;
	tmpi = get_node(stacks->stack_a, i)->next;
	tmpj = get_node(stacks->stack_a, j);
	ops = top(stacks->stack_a, i);
	ops = ft_strjoin(ops, push(stacks->stack_b, stacks->stack_a, 1));
	ops = ft_strjoin(ops, top(stacks->stack_a, tmpj->position));
	ops = ft_strjoin(ops, push(stacks->stack_b, stacks->stack_a, 1));
	ops = ft_strjoin(ops, swap(stacks->stack_b, 1));
	ops = ft_strjoin(ops, push(stacks->stack_a, stacks->stack_b, 1));
	ops = ft_strjoin(ops, top(stacks->stack_a, tmpi->position));
	ops = ft_strjoin(ops, push(stacks->stack_a, stacks->stack_b, 1));
	ops = ft_strjoin(ops, top(stacks->stack_a, tmp_top->position));
	return (ops);
}
