/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:11:35 by aomman            #+#    #+#             */
/*   Updated: 2023/03/01 17:12:06 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_walls(void)
{
	t_ray	ray;
	int		top_p;
	int		down_p;
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;
	t_data	img;

	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3d");
		img.img = mlx_new_image(mlx, WIN_W, WIN_H);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		ray.distance =20001;
		ray.projwall = (WIN_W / 2) / tan(FOV / 2);
		ray.wallstriphiehgt = (TILESIZE / ray.distance) * ray.projwall;
		top_p = (WIN_H / 2) - (ray.wallstriphiehgt / 2);
		down_p = top_p + ray.wallstriphiehgt;
		img.line_length = 10;
		while (j < top_p)
		{
			my_mlx_pixel_put(&img, i, j, 255);
			j++;
		}
		j = 0;
		while (j < top_p)
			mlx_put_image_to_window(mlx, mlx_win, img.img, i, j++);
		mlx_loop(mlx);
		i++;
	}
}
