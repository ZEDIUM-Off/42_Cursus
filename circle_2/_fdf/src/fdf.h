/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/27 23:37:27 by  mchenava        ###   ########.fr       */
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

# define WIDTH	800
# define HEIGHT	600

# define F_SZ_X 1.0f
# define F_SZ_Z 1.0f

# define UNVALID_MAP "fdf: \"%s\" is not a valid map.\n"
# define EMPTY_MAP "fdf: \"%s\" is empty.\n"
# define NO_FDF "fdf: \"%s\" is not a '.fdf' file.\n"
# define NO_FILE "fdf: \"%s\" does not exist.\n"
# define FDF_USAGE "Usage: ./fdf <filename>.fdf\n"

typedef struct s_mlx_env
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_img		*img;
}	t_mlx_env;

typedef struct fdf_uniforms
{
	t_mat4	mvp_mat;
	float	height_max;
	float	height_min;
	t_vec4	color_high;
	t_vec4	color_low;
}	t_fdf_uniforms;

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
	t_fdf_uniforms	uniforms;
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
void	fdf_shader_init(t_fdf *fdf);
int		draw_map(t_fdf *fdf);
void	run_app(t_fdf *fdf);

#endif 