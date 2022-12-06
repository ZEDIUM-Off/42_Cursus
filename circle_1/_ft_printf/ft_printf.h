/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:05:34 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/06 11:24:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);

void	ft_parse_flags(const char *format, va_list args, int *len);
void	ft_on_flag_action(char flag, va_list args, int *len);
void	ft_putchar_fd(char c, int fd, int *len);
void	ft_putstr_fd(char *s, int fd, int *len);
void	ft_putnbr_base(long long nbr, char *base, int *len, int _signed);
void	ft_putptr(unsigned long long n, int *len);

#endif