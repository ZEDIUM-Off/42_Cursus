/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:32:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/06 15:17:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <env3D.h>
# include <X11/keysym.h>
# include "mlx.h"

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
	t_vec4		*cube[8];
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
};

t_mlx_env	*init_mlx_env(void);
int cam_controls(int key, t_mlx_env **env);
void	update_img(t_mlx_env *mlx_env, t_vec4 *cube[8]);
void	my_mlx_pixel_put(t_mlx_env	*env, int x, int y, int color);

#endif