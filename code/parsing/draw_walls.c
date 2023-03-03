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

#include"cub3d.h"
#include<window.h>

int	rgb_to_hex(int	*color)
{
	return ((color[0] << 16) + (color[1] << 8) + (color[2]));
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
		while (j <= down_p)
			ft_pxl_cub(win, i, j++, 0x222223);
		while (j < WIN_H)
			ft_pxl_cub(win, i, j++, rgb_to_hex(win->f_colors));
		i++;
	}
}
