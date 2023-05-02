/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_nl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:51:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/12 10:50:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*no_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}