/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:31:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/02 11:06:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack_state	*stacks;
	int				*values;
	int				size;

	if (argc == 1)
		return (1);
	size = parse_args(argc - 1, &argv);
	if (!size)
		return (disp_err());
	values = extract_values(size, argv);
	ft_free_tab(argv, size);
	stacks = init_a_b(&stack_a, &stack_b, size, values);
	radix(stacks);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	free(stacks);
	return (0);
}
