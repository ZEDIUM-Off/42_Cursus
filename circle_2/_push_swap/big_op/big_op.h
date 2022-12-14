/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:18:57 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 14:34:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_OP_H
# define BIG_OP_H

# include "push_swap.h"

t_node	*get_node(t_stack **stack, int pos);
char	*swap_values(t_stack_state	*stacks, int i, int j);
char	*top(t_stack **stack, int i);

#endif