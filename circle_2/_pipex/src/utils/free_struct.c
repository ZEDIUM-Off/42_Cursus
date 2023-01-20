/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:25:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/20 14:07:02 by  mchenava        ###   ########.fr       */
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

void	free_proc(t_process *stack)
{
	t_process	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}

void	free_pipex(t_pipex **stack)
{
	free_cmd((*stack)->first_cmd);
	free_proc((*stack)->processes);
	free(*stack);
}
