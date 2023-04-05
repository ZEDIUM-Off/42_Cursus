/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/05 14:02:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <lite_gl.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <libft.h>
# include <mlx.h>
# include <mlx_int.h>

# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH	1280
# define HEIGHT 720

# define F_SZ_X 40.0f
# define F_SZ_Z 40.0f

typedef struct s_mlx_env
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_img		*img;
}	t_mlx_env;

typedef struct s_fdf
{
	float			*map;
	unsigned int	*indices;
	int				map_width;
	int				map_height;
	t_mlx_env		mxv;
	t_gl_context	glx;
}	t_fdf;

int		test_file(const char *file_name);
int		read_file(int fd, t_fdf *fdf);
void	init_fdf(t_fdf *fdf);
char	*no_nl(char *str);
int		setup_fdf_data(t_fdf *fdf, int argc, char **argv);
void	init_window(t_fdf *fdf);
void	setup_gl_context(t_fdf *fdf);

#endif 