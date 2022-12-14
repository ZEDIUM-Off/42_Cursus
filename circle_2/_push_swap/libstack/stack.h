/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:37:23 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/14 12:38:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	char			*name;
	unsigned int	size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_stack_state
{
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_stack_state;

void	stack_init(int size, int *values, char *name, t_stack	**stack);
void	display_stack(t_stack *stack);
void	stack_clear(t_stack **stack);

#endif