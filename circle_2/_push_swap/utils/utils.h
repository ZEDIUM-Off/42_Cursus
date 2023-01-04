/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:06:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/04 10:27:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				*extract_values(int numbers, char **values);
int				parse_args(int argc, char ***argv);
int				disp_err(void);
void			act_position(t_stack **stack);

#endif