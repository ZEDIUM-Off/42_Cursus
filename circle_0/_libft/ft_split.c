/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:23:08 by mchenava          #+#    #+#             */
/*   Updated: 2022/11/14 12:07:26 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	i = 0;
	k = 0;
	while (s[i] && ft_count_words(s, c) - k > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		tab[k] = (char *)malloc(sizeof(char) * (j - i + 1));
		j = 0;
		while (s[i] && s[i] != c)
			tab[k][j++] = s[i++];
		tab[k++][j] = '\0';
	}
	tab[k] = NULL;
	return (tab);
}
