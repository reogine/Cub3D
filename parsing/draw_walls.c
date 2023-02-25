/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:11:35 by aomman            #+#    #+#             */
/*   Updated: 2023/02/25 22:59:37 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	ft_put_pixel_to_img(int	top_p, int down_p, void *mlx, void *mlx_win, int i)
{
	if (top_p < WIN_W)
		mlx_pixel_put(mlx, mlx_win, i, 0, 222);
	if (down_p < WIN_W)
		mlx_pixel_put(mlx, mlx_win, i, 0, 0);
}

void	ft_draw_walls(void)
{
	t_ray	*ray;
	
	int		top_p;
	int		down_p;
	void	*mlx;
	void	*mlx_win;
	int		i;

	i = 0;
	while (i < WIN_W)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3d");
		ray = malloc(sizeof(t_ray));
		ray->projwall = (WIN_W / 2) / tan(FOV / 2);
		ray->wallstriphoehjt = (TILESIZE / ray->distance) * ray->projwall;	
		top_p = (ray->projwall / 2) - (WIN_H / 2);
		down_p = (ray->projwall / 2) - (WIN_H / 2);
		ft_put_pixel_to_img(top_p, down_p,  mlx, mlx_win, i);
		ray->angle = 120;
		mlx_loop(mlx);
		free (ray);
	}
}
