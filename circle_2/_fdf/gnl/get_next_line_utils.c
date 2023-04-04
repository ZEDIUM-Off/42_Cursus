/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/04 13:47:29 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > gnl_ft_strlen(s))
		return (gnl_ft_calloc(1, sizeof(char)));
	if (len + start > gnl_ft_strlen(s))
		len = gnl_ft_strlen(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char)
			* (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (str);
}

void	*gnl_ft_calloc(size_t count, size_t size)
{
	void				*ptr;
	unsigned long long	res;
	unsigned char		*ptr_zero;
	size_t				i;

	res = count * size;
	if (res > SIZE_MAX)
		return (NULL);
	ptr = malloc(res);
	if (!ptr)
		return (NULL);
	ptr_zero = (unsigned char *)ptr;
	i = 0;
	while (i < res)
		ptr_zero[i++] = 0;
	return (ptr_zero);
}
