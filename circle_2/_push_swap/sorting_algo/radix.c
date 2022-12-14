/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:22:53 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/13 10:23:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*radix(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		top;
	int		i;
	char	*ops;

	i = 0;
	ops = NULL;
	while (!is_sorted(stack_a))
	{
		size = (*stack_a)->size;
		while (size)
		{
			top = (*stack_a)->top->value;
			if ((top >> i) & 1)
				ops = ft_strjoin(ops, rotate(stack_a, 1));
			else
				ops = ft_strjoin(ops, push(stack_b, stack_a, 1));
			size--;
		}
		while ((*stack_b)->top != NULL)
			ops = ft_strjoin(ops, push(stack_a, stack_b, 1));
		i++;
	}
	return (ops);
}
