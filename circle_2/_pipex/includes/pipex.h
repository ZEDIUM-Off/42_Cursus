/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/20 14:18:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef MAX_SIM_PROCESS
#  define MAX_SIM_PROCESS 64
# endif

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

# include "ft_printf.h"
# include "libft.h"

typedef struct s_cmd		t_cmd;
struct s_cmd {
	char	**cmd;
	t_cmd	*next;
};

typedef struct s_process	t_process;
struct s_process {
	int			pipefd[2];
	pid_t		pid;
	t_process	*next;
};

typedef struct s_pipex
{
	t_cmd			*cmds;
	t_cmd			*first_cmd;
	t_process		*processes;
	char			**env;
	int				infile;
	int				outfile;
}	t_pipex;

t_pipex		*parse(int argc, char **argv, char **envp);

t_process	*init_process(t_pipex **pipex);
t_process	*get_last_process(t_pipex **pipex);

int			proc_count(t_pipex **pipex);

void		pipeline(t_pipex **pipex, int in_fd);
void		free_pipex(t_pipex **stack);
void		new_process(t_pipex **pipex);
void		piping(t_pipex **pipex);
void		close_fd(int fd, t_pipex **pipex);
void		exit_with_error(char *error, t_pipex **pipex);
void		newfd(int oldfd, int newfd, t_pipex **pipex);
void		next_process(t_pipex **pipex);

#endif