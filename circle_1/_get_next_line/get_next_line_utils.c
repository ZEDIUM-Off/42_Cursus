/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:19 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/24 10:36:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
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

// char	*ft_strdup(const char *s)
// {
// 	char	*ptr;
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	ptr = (char *)malloc(sizeof(char) * (i + 1));
// 	if (ptr == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		ptr[i] = s[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
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
