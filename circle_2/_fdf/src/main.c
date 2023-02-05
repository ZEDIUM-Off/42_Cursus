/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:37:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/05 17:27:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include "env3D.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = data->bits_per_pixel - 8;
	//printf("to draw : x=%d, y=%d \n", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (data-> endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (data->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_3d_env	*env;
	t_vec4	*cube[8];

	env = init_env3D(vec4_init(0, 2, -10, 1));
	cube[0] = vec4_init(0, 0, 0, 1);
	cube[1] = vec4_init(0, 0, 1, 1);
	cube[2] = vec4_init(0, 1, 0, 1);
	cube[3] = vec4_init(0, 1, 1, 1);
	cube[4] = vec4_init(1, 0, 0, 1);
	cube[5] = vec4_init(1, 0, 1, 1);
	cube[6] = vec4_init(1, 1, 0, 1);
	cube[7] = vec4_init(1, 1, 1, 1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	for (int i = 0; i < 8; i++)
	{
		//cube[i] = vec4_mul_mat(rotate_y(-50),cube[i]);
		t_vec2 *pixel = proj_point(env, cube[i]);
		my_mlx_pixel_put(&img, (int)(pixel->x), (int)(pixel->y), 0x00FF0000);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
