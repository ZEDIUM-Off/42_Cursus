/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:53:31 by  mchenava         #+#    #+#             */
/*   Updated: 2022/12/09 16:01:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>

# include "stack.h"
# include "stack_op.h"
# include "ft_printf.h"

int		*extract_values(int numbers, char **values);
int		parse_args(int argc, char **argv);
int		disp_err(void);

#endif
