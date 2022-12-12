/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:53:31 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/12 14:17:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>

# include "stack.h"
# include "stack_op.h"
# include "ft_printf.h"
# include "libft.h"
# include "algo.h"

int		*extract_values(int numbers, char **values);
int		parse_args(int argc, char ***argv);
void	init_a_b(t_stack **stack_a, t_stack **stack_b, int size, int *values);
int		disp_err(void);
void	sort(t_stack **stack_a, t_stack **stack_b);

#endif
