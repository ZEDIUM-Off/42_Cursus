/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:59:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/17 13:39:01 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex **pipex, int in_fd)
{
	ft_printf(1, "child_process... %s %s %d\n", (*pipex)->cmds->cmd[0], (*pipex)->cmds->cmd[1], in_fd);
	close_fd((*pipex)->processes->pipefd[0]);
	newfd(in_fd, STDIN_FILENO);
	newfd((*pipex)->processes->pipefd[1], STDOUT_FILENO);
	if (execve((*pipex)->cmds->cmd[0],
			(*pipex)->cmds->cmd, (*pipex)->env) == -1)
		exit_with_error("execve");
}

void	parent_process(t_pipex **pipex, int in_fd)
{
	ft_printf(1, "parent_process... %s %s %d\n", (*pipex)->cmds->cmd[0], (*pipex)->cmds->cmd[1], in_fd);
	close_fd((*pipex)->processes->pipefd[1]);
	close_fd(in_fd);
	(*pipex)->cmds = (*pipex)->cmds->next;
	pipeline(pipex, (*pipex)->processes->pipefd[0]);
}

void	last_process(t_pipex **pipex, int in_fd)
{
	ft_printf(1, "last_process... %s %s %d\n", (*pipex)->cmds->cmd[0], (*pipex)->cmds->cmd[1], in_fd);
	newfd(in_fd, (*pipex)->outfile);
	if (execve((*pipex)->cmds->cmd[0],
			(*pipex)->cmds->cmd, (*pipex)->env) == -1)
		exit_with_error("execve");
}

void	wait_for_process(t_pipex **pipex)
{
	int			status;
	t_process	*last;
	t_process	*tmp;

	last = get_last_process(pipex);
	waitpid(last->pid, &status, 0);
	tmp = (*pipex)->processes;
	(*pipex)->processes = (*pipex)->processes->next;
	free(tmp);
}

void	pipeline(t_pipex **pipex, int in_fd)
{
	if (!((*pipex)->cmds->next))
	{
		last_process(pipex, in_fd);
		return ;
	}
	else
	{
		if (proc_count(pipex) >= MAX_SIM_PROCESS)
			wait_for_process(pipex);
		new_process(pipex);
		piping(pipex);
		if ((*pipex)->processes->pid == 0)
			child_process(pipex, in_fd);
		else
			parent_process(pipex, in_fd);
	}
}
