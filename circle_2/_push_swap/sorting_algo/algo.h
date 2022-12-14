/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:28:12 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 15:04:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

char	*radix(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);
char	*quick(t_stack_state	*stacks);

#endif