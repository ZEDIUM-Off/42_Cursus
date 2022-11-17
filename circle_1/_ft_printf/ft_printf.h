/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:05:34 by  mchenava         #+#    #+#             */
/*   Updated: 2022/11/17 10:51:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_intlen(int n);
size_t	ft_uintlen(unsigned int n);
size_t	ft_hexlen(unsigned long long n);

int		ft_parse_flags(const char *format, va_list args);
int		ft_on_flag_action(char flag, va_list args);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putptr_fd(void *ptr, int fd);
int		ft_puthex_fd(unsigned long long n, int fd, int upper);
int		ft_printf(const char *format, ...);
int		ft_toupper(int c);
int		ft_putnull_fd(int fd);

#endif