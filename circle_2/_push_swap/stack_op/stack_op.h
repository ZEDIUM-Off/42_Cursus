/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:41:02 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 13:35:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OP_H
# define STACK_OP_H

# include "stack.h"
# include <unistd.h>

char	*both(
			t_stack **stack_1,
			t_stack **stack_2,
			void (*op)(t_stack **, int),
			char *str
			);
char	*swap(t_stack **stack, int disp_op);
char	*push(t_stack **stack_in, t_stack **stack_out, int disp_op);
char	*rotate(t_stack **stack, int disp_op);
char	*rev_rotate(t_stack **stack, int disp_op);

#endif