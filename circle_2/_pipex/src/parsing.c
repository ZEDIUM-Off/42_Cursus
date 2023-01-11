/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:02:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/11 13:10:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_c

t_pipex	*parse(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmds;
	t_file	*infile;
	t_file	*outfile;

	if (argc < 5)
		return (NULL);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->cmds = parse_cmds(argc, argv, envp);
	pipex->infile = parse_infile(argc, argv, envp);
	pipex->outfile = parse_outfile(argc, argv, envp);
}
