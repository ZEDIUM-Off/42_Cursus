/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:25:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/16 10:55:42 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd *stack)
{
	t_cmd	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		ft_free_tab(tmp->cmd, ft_tablen(tmp->cmd));
		free(tmp);
	}
	free(stack);
}

void	free_pipex(t_pipex **stack)
{
	free_cmd((*stack)->cmds);
	free(*stack);
}
