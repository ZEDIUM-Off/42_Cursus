/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:35:01 by mchenava          #+#    #+#             */
/*   Updated: 2022/11/09 14:22:13 by mchenava         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int		test_ft_int(int (*ref_func)(int), int (*to_test)(int));
char	**parse_args(char **args);
int		err_handle(int a);

int	main(void)
{
	if (test_ft_int(&isalpha, &ft_isalpha) != 0)
		return (err_handle(1000 + test_ft_int(&isalpha, &ft_isalpha)));
	if (test_ft_int(&isdigit, &ft_isdigit) != 0)
		return (err_handle(2000 + test_ft_int(&isdigit, &ft_isdigit)));
	if (test_ft_int(&isalnum, &ft_isalnum) != 0)
		return (err_handle(3000 + test_ft_int(&isalnum, &ft_isalnum)));
	if (test_ft_int(&isascii, &ft_isascii) != 0)
		return (test_ft_int(&isascii, &ft_isascii));
	if (test_ft_int(&isprint, &ft_isprint) != 0)
		return (test_ft_int(&isprint, &ft_isprint));
	return (0);
}

int	err_handle(int a)
{
	char	*err_message;

	if (a / 1000 == 1)
		err_message = "[ft_isalpha ERR]";
	if (a / 1000 == 2)
		err_message = "[ft_isdigit ERR]";
	if (a / 1000 == 3)
		err_message = "[ft_isalnum ERR]";
	printf("%s - Erreur survenue au test n.%d\n", err_message, a % 1000);
	return (1);
}

int	test_ft_int(int (*ref_func)(int), int (*to_test)(int))
{
	int	i;

	i = -20;
	while (i <= 300)
	{
		if ((*ref_func)(i) != (*to_test)(i))
			return (i);
		i++;
	}
	return (0);
}
