/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:04 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/16 10:32:07 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_tab(void *tab, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(((char **)tab)[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
