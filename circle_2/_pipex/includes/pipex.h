/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/13 10:58:15 by  mchenava        ###   ########.fr       */
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

typedef struct s_cmd	t_cmd;
struct s_cmd {
	char	**cmd;
	t_cmd	*next;
};

typedef struct s_pipex
{
	int		*infile;
	int		*outfile;
	t_cmd	*cmds;
}	t_pipex;

#endif