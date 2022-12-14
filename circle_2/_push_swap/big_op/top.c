/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:32:39 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 14:36:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*top(t_stack **stack, int i)
{
	char	*ops;
	int		k;

	ops = NULL;
	if (i > (int)(*stack)->size / 2)
	{
		k = 0;
		while (k < (int)(*stack)->size - i)
		{
			ops = ft_strjoin(ops, rev_rotate(stack, 1));
			k++;
		}
	}
	else
	{
		k = 0;
		while (k < i)
		{
			ops = ft_strjoin(ops, rotate(stack, 1));
			k++;
		}
	}
	return (ops);
}
