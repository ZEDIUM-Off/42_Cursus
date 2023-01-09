/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:06:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/09 10:35:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				*extract_values(int numbers, char **values);
int				parse_args(int argc, char ***argv);
int				disp_err(int size);
void			act_position(t_stack **stack);

#endif