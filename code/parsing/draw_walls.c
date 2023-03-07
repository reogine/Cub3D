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

int	horizontal_texture(t_window *win, t_ray *ray, int y)
{
	char	*tile_buffer;
	t_data	img_set;

	if (ray->face_up == 0)
		tile_buffer = mlx_get_data_addr(win->so_text, &img_set.bits_per_pixel,
				&img_set.line_length, &img_set.endian);
	else
		tile_buffer = mlx_get_data_addr(win->no_text, &img_set.bits_per_pixel,
				&img_set.line_length, &img_set.endian);
	tile_buffer = tile_buffer + ((int)(y * ((double)TEX_H
					/ (double)ray->wallstriphiehgt)) *img_set.line_length
			+ ((int)(ray->hit_x) % TEX_W) * (img_set.bits_per_pixel / 8));
	return (*(int *)tile_buffer);
}

int	vertical_texture(t_window *win, t_ray *ray, int y)
{
	char	*tile_buffer;
	t_data	img_set;

	if (ray->face_left == 0)
		tile_buffer = mlx_get_data_addr(win->ea_text, &img_set.bits_per_pixel,
				&img_set.line_length, &img_set.endian);
	else
		tile_buffer = mlx_get_data_addr(win->we_text, &img_set.bits_per_pixel,
				&img_set.line_length, &img_set.endian);
	tile_buffer = tile_buffer + ((int)(y * ((double)TEX_H
					/ (double)ray->wallstriphiehgt)) *img_set.line_length
			+ ((int)(ray->hit_y) % TEX_W) * (img_set.bits_per_pixel / 8));
	return (*(int *)tile_buffer);
}

int	set_color_from_texture(t_window *win, t_ray *ray, int y)
{
	if (ray->is_horizontal)
		return (horizontal_texture(win, ray, y));
	return (vertical_texture(win, ray, y));
}

void	calcul_setting(t_window *win, t_ray *ray, int i)
{
	*ray = win->rays[i];
	ray->corr_d = cos(ray->angle - win->ply.rot_ang) * ray->distance;
	ray->projwall = (WIN_W / 2) / tan((FOV * (P / 180)) / 2);
	ray->wallstriphiehgt = (TILESIZE / ray->corr_d) * ray->projwall;
	ray->top_p = (WIN_H / 2) - (ray->wallstriphiehgt / 2);
	ray->down_p = ray->top_p + ray->wallstriphiehgt;
}

void	ft_draw_walls(t_window *win)
{
	t_ray	ray;
	int		i;
	int		j;

	i = 0;
	while (i < WIN_W)
	{
		calcul_setting(win, &ray, i);
		j = 0;
		while (j < ray.top_p)
			ft_pxl_cub(win, i, j++, rgb_to_hex(win->c_colors));
		while (j < ray.down_p && j < WIN_H)
		{
			ft_pxl_cub(win, i, j, set_color_from_texture(win, &ray, j
					- ray.top_p));
			if (i < 0 || j < 0)
				break ;
			j++;
		}
		while (j < WIN_H)
			ft_pxl_cub(win, i, j++, rgb_to_hex(win->f_colors));
		i++;
	}
}
