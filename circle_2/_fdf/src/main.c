/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:37:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/31 13:05:09 by  mchenava        ###   ########.fr       */
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
	printf("to draw : x=%d, y=%d \n", x, y);
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
	t_3d_env	env;
	t_vec2		*pixel;

	env.world = vec3_init(1, 1, 1);
	printf("env.world init\n");
	env.world_camera = mat4_init(x);
	printf("env.world-cam init\n");
	env.screen_width = 2;
	env.screen_height = 2;
	env.render_width = 512;
	env.render_height = 512;
	pixel = compute_pixel(&env);
	printf("coo: x=%f, y=%f\n", pixel->x, pixel->y);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 512, 512, "Hello world!");
	img.img = mlx_new_image(mlx, 512, 512);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, (int)pixel->x, -(int)pixel->y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
