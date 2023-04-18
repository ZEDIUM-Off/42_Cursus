/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/17 11:58:09 by  mchenava        ###   ########.fr       */
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

# define WIDTH	720
# define HEIGHT 720

# define F_SZ_X 1.0f
# define F_SZ_Z 1.0f

typedef struct s_mlx_env
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_img		*img;
}	t_mlx_env;

typedef struct s_fdf
{
	float			*map;
	t_gl_uint		*indices;
	t_gl_uint		map_vbo;
	t_gl_uint		map_ibo;
	size_t			map_size;
	size_t			indices_size;
	size_t			map_width;
	size_t			map_height;
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
void	set_map_buffers(t_fdf *fdf);
t_mat4	isometric_view(void);

#endif 