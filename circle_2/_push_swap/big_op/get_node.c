/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:18:02 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 15:13:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node(t_stack **stack, int pos)
{
	t_node	*tmp;

	tmp = (*stack)->top;
	while (pos)
	{
		tmp = tmp->next;
		pos--;
	}
	return (tmp);
}
