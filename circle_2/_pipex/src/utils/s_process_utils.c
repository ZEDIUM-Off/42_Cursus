/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_process_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:24:24 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/20 12:56:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_process	*get_last_process(t_pipex **pipex)
{
	t_process	*tmp;

	tmp = (*pipex)->processes;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_process	*init_process(t_pipex **pipex)
{
	t_process	*new;

	new = malloc(sizeof(t_process));
	if (!new)
		exit_with_error("malloc", pipex);
	new->next = NULL;
	return (new);
}

int	proc_count(t_pipex **pipex)
{
	int			i;
	t_process	*tmp;

	i = 0;
	tmp = (*pipex)->processes;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	new_process(t_pipex **pipex)
{
	(*pipex)->processes->pid = fork();
	if ((*pipex)->processes->pid == -1)
		exit_with_error("fork", pipex);
}

void	next_process(t_pipex **pipex)
{
	t_process	*new;

	new = init_process(pipex);
	new->next = (*pipex)->processes;
	(*pipex)->processes = new;
}
