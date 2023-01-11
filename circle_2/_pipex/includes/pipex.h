/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/11 13:04:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef MAX_SIM_PROCESS
#  define MAX_SIM_PROCESS 16
# endif

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*path;
	t_cmd	*next;
}	t_cmd;

typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;

typedef struct s_pipex
{
	t_file	*infile;
	t_file	*outfile;
	t_cmd	*cmds;
}	t_pipex;

#endif