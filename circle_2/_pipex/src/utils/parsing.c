/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:02:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/15 19:36:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*match_path(char **path_list, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path_list[i])
	{
		tmp = ft_strsepjoin(path_list[i], cmd, '/');
		if (access(tmp, F_OK) == 0)
			return (ft_free_tab(path_list, i), tmp);
		i++;
		free(tmp);
	}
	return (ft_printf(2, "pipex: %s: command not found\n", cmd),
		ft_free_tab(path_list, i), cmd);
}

char	**find_cmd(char *cmd, char **envp)
{
	char	**path;
	char	**_cmd;
	int		i;

	_cmd = ft_split(cmd, ' ');
	if (access(_cmd[0], F_OK) == 0)
		return (_cmd);
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(envp[i], ':');
	i = 0;
	_cmd[0] = match_path(path, _cmd[0]);
	if (!_cmd[0])
		return (NULL);
	return (_cmd);
}

t_cmd	*parse_cmds(int argc, char **argv, char **envp)
{
	t_cmd	*cmds;
	t_cmd	*tmp;
	int		i;

	cmds = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmds)
		return (NULL);
	i = 0;
	tmp = cmds;
	while (i < argc - 3)
	{
		cmds->cmd = find_cmd(argv[i + 2], envp);
		if (!cmds->cmd)
			return (NULL);
		cmds->next = (t_cmd *)malloc(sizeof(t_cmd));
		cmds = cmds->next;
		i++;
	}
	cmds->next = NULL;
	return (tmp);
}

void	display_cmds(t_cmd *cmds)
{
	int		i;
	t_cmd	*tmp;

	tmp = cmds;
	while (tmp->next)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			ft_printf(1, "%s ", tmp->cmd[i]);
			i++;
		}
		ft_printf(1, "\n");
		tmp = tmp->next;
	}
}

t_pipex	*parse(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->cmds = parse_cmds(argc, argv, envp);
	if (!pipex->cmds)
		return (NULL);
	display_cmds(pipex->cmds);
	return (pipex);
}