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

void	ft_draw_walls(t_window *win)
{
	t_ray	ray;
	int		top_p;
	int		down_p;
	int		i;
	int		j;

	// ray = NULL;
	i = 0;
	while (i < WIN_W)
	{
		printf("here\n");
		j = 0;
		ray = win->rays[i];
		ray.projwall = (WIN_W / 2) / tan(FOV / 2);
		printf("%f\n", ray.distance);
		ray.wallstriphiehgt = (TILESIZE / ray.distance) * ray.projwall;
		top_p = (WIN_H / 2) - (ray.wallstriphiehgt / 2);
		down_p = top_p + ray.wallstriphiehgt;
		while (j < top_p)
		{
			printf("%d\n%d\n", i, j);
			ft_pxl_cub(win->fps, i, j, 255);
			j++;
		}
		i++;
	}
}
