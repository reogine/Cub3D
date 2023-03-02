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
#include<window.h>

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
		ray.projwall = (WIN_W / 2) / tan(FOV / 2);
		ray.wallstriphiehgt = (TILESIZE / ray.distance) * ray.projwall;
		top_p = (WIN_H / 2) - (ray.wallstriphiehgt / 2);
		down_p = top_p + ray.wallstriphiehgt;
		j = 0;
		while (j < top_p)	
			ft_pxl_cub(win->fps, i, j++, 0xFEDD00);
		i++;
	}
	printf("out\n");
}
