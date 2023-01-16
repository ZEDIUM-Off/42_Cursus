/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:45:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/16 10:00:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_printf(2, "pipex: not enough arguments\
			\nusage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"), 1);
	pipex = parse(argc, argv, envp);
	if (!pipex)
		return (free_pipex(&pipex), 1);
	return (free_pipex(&pipex), 0);
}
