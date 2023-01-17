/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/17 12:29:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef MAX_SIM_PROCESS
#  define MAX_SIM_PROCESS 16
# endif

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

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
	t_process		*processes;
	char			**env;
	int				infile;
	int				outfile;
}	t_pipex;

t_pipex		*parse(int argc, char **argv, char **envp);

t_process	*init_process(void);
t_process	*get_last_process(t_pipex **pipex);

int			proc_count(t_pipex **pipex);

void		pipeline(t_pipex **pipex, int in_fd);
void		free_pipex(t_pipex **stack);
void		new_process(t_pipex **pipex);
void		piping(t_pipex **pipex);
void		close_fd(int fd);
void		exit_with_error(char *error);
void		newfd(int oldfd, int newfd);

#endif