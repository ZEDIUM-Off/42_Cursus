/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:19 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/21 15:35:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_size(int fd)
{
	size_t	size;
	int		act_pos;
	char	buffer[1];

	if (fd < 0)
		return (-1);
	size = 0;
	act_pos = 1;
	while (act_pos)
	{
		act_pos = read(fd, buffer, 1);
		size++;
	}
	return (size);
}
