/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:31:50 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/12 10:32:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*values;

	if (argc == 1)
		return (1);
	if (!parse_args(argc - 1, argv + 1))
		return (disp_err());
	values = extract_values(argc - 1, argv + 1);
	init_a_b(&stack_a, &stack_b, argc - 1, values);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
