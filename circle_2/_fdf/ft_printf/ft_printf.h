/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:05:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/13 14:31:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(int fd, const char *format, ...);
size_t	ft_strlen(const char *s);

void	ft_parse_flags(int fd, const char *format, va_list args, int *len);
void	ft_on_flag_action(int fd, char flag, va_list args, int *len);
void	pf_putchar_fd(char c, int fd, int *len);
void	pf_putstr_fd(char *s, int fd, int *len);
void	ft_putnbr_base(long long nbr, char *base, int *len, int _signed);

#endif