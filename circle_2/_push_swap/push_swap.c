/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:31:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/04 10:29:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				*values;
	int				size;

	if (argc == 1)
		return (1);
	size = parse_args(argc - 1, &argv);
	if (!size)
		return (disp_err());
	values = extract_values(size, argv);
	ft_free_tab(argv, size);
	stack_init(size, values, "a", &stack_a);
	stack_init(0, NULL, "b", &stack_b);
	free(values);
	radix(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
