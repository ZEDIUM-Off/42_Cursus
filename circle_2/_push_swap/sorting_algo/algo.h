/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:28:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/09 10:18:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b);

#endif