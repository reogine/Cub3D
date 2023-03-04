/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:11:35 by aomman            #+#    #+#             */
/*   Updated: 2023/03/03 19:35:16 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <window.h>

int	rgb_to_hex(int *color)
{
	return ((color[0] << 16) + (color[1] << 8) + (color[2]));
}

int	set_color_from_texture(t_window *win, t_ray *ray, int y)
{
	char	*tile_buffer;
	t_data	img_set;

	tile_buffer = mlx_get_data_addr(win->so_text, &img_set.bits_per_pixel,
			&img_set.line_length, &img_set.endian);
	if (ray->is_horizontal)
		tile_buffer = tile_buffer + ((int)(y * ((double)TEX_H
						/ (double)ray->wallstriphiehgt)) * img_set.line_length
				+ ((int)(ray->hit_x) % TEX_W) * (img_set.bits_per_pixel / 8));
	else
		tile_buffer = tile_buffer + ((int)(y * ((double)TEX_H
						/ (double)ray->wallstriphiehgt)) * img_set.line_length
				+ ((int)(ray->hit_y) % TEX_W) * (img_set.bits_per_pixel / 8));
	return (*(int *)tile_buffer);
}

void	ft_draw_walls(t_window *win)
{
	t_ray	ray;
	int		top_p;
	int		down_p;
	int		i;
	int		j;

	i = 0;
	while (i < WIN_W)
	{
		ray = win->rays[i];
		ray.corr_d = cos(ray.angle - win->ply.rot_ang) * ray.distance;
		ray.projwall = (WIN_W / 2) / tan((FOV * (P / 180)) / 2);
		ray.wallstriphiehgt = (TILESIZE / ray.corr_d) * ray.projwall;
		top_p = (WIN_H / 2) - (ray.wallstriphiehgt / 2);
		down_p = top_p + ray.wallstriphiehgt;
		j = 0;
		while (j < top_p)
			ft_pxl_cub(win, i, j++, rgb_to_hex(win->c_colors));
		while (j < down_p && j < WIN_H)
		{
			ft_pxl_cub(win, i, j, set_color_from_texture(win, &ray, j - top_p));
			j++;
		}
		while (j < WIN_H)
			ft_pxl_cub(win, i, j++, rgb_to_hex(win->f_colors));
		i++;
	}
}
