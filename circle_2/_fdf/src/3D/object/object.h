/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:14:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/08 12:36:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_obj	t_obj;
typedef struct s_vertex	t_vertex;
typedef struct s_edge	t_edge;

struct s_vertex
{
	t_vec4		*coords;
	t_vertex	*next;
	int			index;
};

struct s_edge
{
	t_vec4	*start;
	t_vec4	*end;
	t_edge	*next;
};

struct s_obj
{
	char			*name;
	t_vertex		*vertices;
	t_edge			*edges;
};

#endif