/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/03/01 02:50:00 by midfath          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "parsing/cub3d.h"
#include <window.h>

void	render_minimap(t_window *w)
{
	mini_map_display(w);
	rays_display(w);
	ply_display(w);
	mini_map_overlay(w);
}

void	mini_map_overlay(t_window *win)
{
	t_xy	cordo;
	t_xy	str;
	int		clr;

	str.x = win->ply.x - 70;
	str.y = win->ply.y - 70;
	cordo.y = 0;
	cordo.x = 0;
	while (cordo.y < 140)
	{
		clr = get_pxl_minimap(win, str.x + cordo.x, str.y + cordo.y);
		if (clr <= 0)
			clr = 0x101541;
		ft_pxl_cub(win, cordo.x + WIN_W - 140, cordo.y, clr);
		cordo.x++;
		if (cordo.x == 140)
		{
			cordo.x = 0;
			cordo.y++;
		}
	}
}

t_window	*init_win(t_var *var)
{
	t_window	*win;

	// init_tx(win);
	win = (t_window *)malloc(sizeof(t_window));
	win->x = 0;
	win->y = 0;
	win->mlx = mlx_init();
	win->height = WIN_H;
	win->width = WIN_W;
	win->map = var->map_elmnt;
	win->mini_map.row = ft_strlen(win->map[0]);
	win->mini_map.col = map_lines(win->map);
	win->f_colors = var->f_colors;
	win->c_colors = var->c_colors;
	win->path_so = var->path_so;
	win->path_no = var->path_no;
	win->path_ea = var->path_ea;
	win->path_we = var->path_we;
	win->win_ptr = mlx_new_window(win->mlx, win->width, win->height, "game");
	win->fps = mlx_new_image(win->mlx, win->width, win->height);
	win->addr_fps = mlx_get_data_addr(win->fps, &win->fps_bpp,
			&win->fps_sizeline, &win->fps_endian);
	win->mini_map.img = mlx_new_image(win->mlx,
										win->mini_map.row * TILESIZE,
										win->mini_map.col * TILESIZE);
	win->mini_map.addr = mlx_get_data_addr(win->mini_map.img,
			&win->mini_map.bpp, &win->mini_map.sizeline, &win->mini_map.endian);
	init_ply(win);
	return (win);
}

void	mini_map_display(t_window *win)
{
	t_xy	cordo;

	if ((int)(win->ply.y / TILESIZE) < 5)
		cordo.y = 0;
	else
		cordo.y = ((int)(win->ply.y / TILESIZE) - 5);
	while (win->map[cordo.y] && cordo.y < (int)(win->ply.y / TILESIZE) + 10)
	{
		if ((int)(win->ply.x / TILESIZE) < 5)
			cordo.x = 0;
		else
			cordo.x = ((int)(win->ply.x / TILESIZE) - 5);
		while (win->map[cordo.y][cordo.x] && cordo.x < (int)(win->ply.x
				/ TILESIZE) + 10)
		{
			if (win->map[cordo.y][cordo.x] == '1')
				ft_pxl_block(win, cordo, 0x444444);
			else if (ft_strchr("0NSWE", win->map[cordo.y][cordo.x]))
				ft_pxl_block(win, cordo, 0x7B7C7D);
			cordo.x++;
		}
		cordo.y++;
	}
}
