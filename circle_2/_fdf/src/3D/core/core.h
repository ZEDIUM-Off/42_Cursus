/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:48:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/24 11:03:01 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "lib3d.h"

typedef struct s_core	t_core;
typedef struct s_window	t_window;
typedef struct s_time	t_time;

struct s_time
{
	unsigned int	fps;
	float			current;
	float			prev;
	float			update;
	float			draw;
	float			frame;
	float			target;
};

struct s_window
{
	consr char	*title;
	bool		ready;
	bool		fullscreen;
	bool		should_close;
	bool		event_waiting;
	float		width;
	float		height;
};

struct s_core
{
	t_window	*window;
	t_time		*time;
};

void	set_target_fps(t_core *core, unsigned int fps);

#endif