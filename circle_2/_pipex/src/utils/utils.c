/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:36:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/17 13:00:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	newfd(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close_fd(oldfd);
	}
}

void	exit_with_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	close_fd(int fd)
{
	if (close(fd) == -1)
		exit_with_error("close");
}

void	piping(t_pipex **pipex)
{
	if (pipe((*pipex)->processes->pipefd) == -1)
		exit_with_error("pipe");
}
