/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/02 16:00:35 by  mchenava        ###   ########.fr       */
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
# include <stdbool.h>

# define WIDTH	800
# define HEIGHT	600

# define F_SZ_X 1.0f
# define F_SZ_Z 1.0f

# define UNVALID_MAP "fdf: \"%s\" is not a valid map.\n"
# define EMPTY_MAP "fdf: \"%s\" is empty.\n"
# define NO_FDF "fdf: \"%s\" is not a '.fdf' file.\n"
# define NO_FILE "fdf: \"%s\" does not exist.\n"
# define FDF_USAGE "Usage: ./fdf <filename>.fdf\n"

enum {
	KEY_PRESSED_EVT = 02,
	KEY_RELEASED_EVT = 03,
	BUTTON_PRESSED_EVT = 04,
	BUTTON_RELEASED_EVT = 05,
	MOUSE_MOVE_EVT = 06,
};

enum {
	KEY_PRESSED_MASK = (1L << 0),
	KEY_RELEASED_MASK = (1L << 1),
	BUTTON_PRESSED_MASK = (1L << 2),
	BUTTON_RELEASED_MASK = (1L << 3),
	MOUSE_MOVE_MASK = (1L << 6),
};

enum {
	LEFT_CLICK = 1,
	RIGHT_CLICK,
	MIDDLE_CLICK,
	SCROLL_UP,
	SCROLL_DOWN,
};

typedef struct s_fdf	t_fdf;

typedef struct s_mlx_env
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_img		*img;
}	t_mlx_env;

typedef t_mat4 (*		t_proj_func) (t_fdf *);
typedef struct fdf_uniforms
{
	t_mat4		mvp_mat;
	float		height_max;
	float		height_min;
	t_vec4		color_high;
	t_vec4		color_low;
	t_proj_func	project;
}	t_fdf_uniforms;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	target;
	t_vec3	dir;
	t_vec3	up;
	t_vec3	right;
	float	speed;
	float	zoom;
}	t_cam;

typedef struct s_controls
{
	bool	rotate;
	t_vec2	mouse_pos;
}	t_ctrl;
struct s_fdf
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
	t_cam			cam;
	t_ctrl			ctrl;
};

int		test_file(const char *file_name);
int		read_file(int fd, t_fdf *fdf);
void	init_fdf(t_fdf *fdf);
char	*no_nl(char *str);
int		setup_fdf_data(t_fdf *fdf, int argc, char **argv);
void	init_window(t_fdf *fdf);
void	setup_gl_context(t_fdf *fdf);
void	set_map_buffers(t_fdf *fdf);
t_mat4	isometric_view(t_fdf *fdf);
t_mat4	cam_proj(t_fdf *fdf);
void	fdf_shader_init(t_fdf *fdf);
int		draw_map(t_fdf *fdf);
void	run_app(t_fdf *fdf);
void	set_hooks(t_fdf	*fdf);
void	init_cam(t_fdf	*fdf);
int		mouse_pressed(int btn, int x, int y, t_fdf *fdf);
int		mouse_released(int btn, int x, int y, t_fdf *fdf);
int		mouse_move(int x, int y, t_fdf *fdf);
void	cam_rotate(t_fdf *fdf, float delta_x, float delta_y);

#endif 