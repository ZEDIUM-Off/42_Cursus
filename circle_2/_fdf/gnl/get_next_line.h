/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/04 13:45:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define FD_MAX 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);
char	*gnl_ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_strchr(const char *s, int c);

void	*gnl_ft_calloc(size_t count, size_t size);

size_t	gnl_ft_strlen(const char *s);

#endif