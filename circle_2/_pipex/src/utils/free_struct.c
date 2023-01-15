/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:25:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/15 19:30:18 by  mchenava        ###   ########.fr       */
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
		free(tmp->cmd);
		free(tmp);
	}
}

void	free_pipex(t_pipex **stack)
{
	free_cmd((*stack)->cmds);
	free(*stack);
}
