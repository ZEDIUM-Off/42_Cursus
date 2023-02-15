/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:32:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/08 16:26:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <env3D.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <libft.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1600.00
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 900.00
# endif

# ifndef WIN_TITLE
#  define WIN_TITLE "fdf"
# endif

typedef struct s_mlx_env	t_mlx_env;

struct s_mlx_env
{
	t_3d_env	*env3d;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bpp;
	int			line_len;
	int			endian;
};

t_mlx_env	*init_mlx_env(void);
int			cam_controls(int key, t_mlx_env **env);
void		update_img(t_mlx_env *mlx_env);
void		pixel_put(t_mlx_env	*env, int x, int y, int color);
void		draw_object(t_mlx_env *mlx_env, t_obj *object);

#endif