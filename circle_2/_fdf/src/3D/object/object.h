/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:14:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:15:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_obj	t_obj;
typedef struct s_vertex	t_vertex;
typedef struct s_face  t_face;

struct s_vertex
{
	t_vec4		*coords;
	t_vertex	*next;
	int				index;
};

struct s_face
{
	int				vertices[3];
  t_face    *next;
};

struct s_obj
{
	char			*name;
	t_vertex	*vertices;
	t_face		*faces;
};

#endif