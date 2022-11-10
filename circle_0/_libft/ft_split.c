/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:23:08 by marvin            #+#    #+#             */
/*   Updated: 2022/11/10 17:39:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	i = 0;
	k = 0;
	while (src[i])
	{
		while (src[i] && src[i] == c)
			i++;
		j = i;
		while (src[j] && src[j] != c)
			j++;
		tab[k] = (char *)malloc(sizeof(char) * (j - i + 1));
		j = 0;
		while (src[i] && src[i] != c)
			tab[k][j++] = src[i++];
		tab[k++][j] = '\0';
	}
	tab[k] = 0;
	return (tab);
}