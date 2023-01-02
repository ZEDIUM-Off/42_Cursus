/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:41:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/02 10:48:42 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OP_H
# define STACK_OP_H

# include "stack.h"
# include <unistd.h>

void	both(
			t_stack **stack_1,
			t_stack **stack_2,
			void (*op)(t_stack **, int),
			char *str
			);
void	swap(t_stack **stack, int disp_op);
void	push(t_stack **stack_in, t_stack **stack_out, int disp_op);
void	rotate(t_stack **stack, int disp_op);
void	rev_rotate(t_stack **stack, int disp_op);

#endif