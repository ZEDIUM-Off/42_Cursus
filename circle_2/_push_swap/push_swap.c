/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:31:50 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/09 17:20:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*values;

	if (!parse_args(argc - 1, argv + 1))
		return (disp_err());
	values = extract_values(argc - 1, argv + 1);
	stack_a = stack_init(argc - 1, values, "a");
	stack_b = stack_init(0, NULL, "b");
	free(values);
	display_stack(stack_a);
	push(&stack_b, &stack_a, 1);
	display_stack(stack_b);
	display_stack(stack_a);
	stack_clear(stack_a);
	stack_clear(stack_b);
	return (0);
}
