/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:02:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/13 12:32:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*parse_cmds(int argc, char **argv, char **envp)
{
	t_cmd	*cmds;
	int		i;

	cmds = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmds)
		return (NULL);
	i = 0;
	while (i < argc - 3)
	{
		cmds->cmd = find_cmd(argv[i + 2], envp);
		if (cmds->cmd)
			return (NULL);
		cmds->next = (t_cmd *)malloc(sizeof(t_cmd));
		cmds = cmds->next;
		i++;
	}
	cmds->next = NULL;
	return (cmds);
}

t_pipex	*parse(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	return (pipex);
}
