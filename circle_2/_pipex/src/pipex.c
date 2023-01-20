/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:59:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/20 15:02:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex **pipex, int in_fd)
{
	close_fd((*pipex)->processes->pipefd[0], pipex);
	newfd(in_fd, STDIN_FILENO, pipex);
	newfd((*pipex)->processes->pipefd[1], STDOUT_FILENO, pipex);
	if (execve((*pipex)->cmds->cmd[0],
			(*pipex)->cmds->cmd, (*pipex)->env) == -1)
		exit(1);
}

void	parent_process(t_pipex **pipex, int in_fd)
{
	t_process	*tmp;

	close_fd((*pipex)->processes->pipefd[1], pipex);
	if (in_fd >= 0)
		close_fd(in_fd, pipex);
	tmp = (*pipex)->processes;
	(*pipex)->cmds = (*pipex)->cmds->next;
	next_process(pipex);
	pipeline(pipex, tmp->pipefd[0]);
}

void	last_process(t_pipex **pipex, int in_fd)
{
	newfd(in_fd, STDIN_FILENO, pipex);
	newfd((*pipex)->outfile, STDOUT_FILENO, pipex);
	if (execve((*pipex)->cmds->cmd[0],
			(*pipex)->cmds->cmd, (*pipex)->env) == -1)
		exit_with_error("execve", pipex);
}

void	wait_for_process(t_pipex **pipex)
{
	int			status;
	t_process	*last;
	t_process	*tmp;

	last = get_last_process(pipex);
	waitpid(last->pid, &status, 0);
	tmp = (*pipex)->processes;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	close_fd(last->pipefd[0], pipex);
	close_fd(last->pipefd[1], pipex);
	free(last);
}

void	pipeline(t_pipex **pipex, int in_fd)
{
	if (!((*pipex)->cmds->next))
		last_process(pipex, in_fd);
	else
	{
		if (proc_count(pipex) >= MAX_SIM_PROCESS)
			wait_for_process(pipex);
		piping(pipex);
		new_process(pipex);
		if ((*pipex)->processes->pid == 0)
			child_process(pipex, in_fd);
		else
			parent_process(pipex, in_fd);
	}
}
