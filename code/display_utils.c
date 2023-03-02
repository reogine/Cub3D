/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:11:24 by midfath           #+#    #+#             */
/*   Updated: 2023/03/01 18:57:12 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

int       valid_des(t_window *w, double nxt_x, double nxt_y)
{
		int curr_y = (int)(w->ply.y / TILESIZE);
		int curr_x = (int)(w->ply.x / TILESIZE);
		int next_y_cell = (int)(nxt_y / TILESIZE);
		int next_x_cell = (int)(nxt_x / TILESIZE);

		if (w->map[next_y_cell][next_x_cell] != '0')
				return (2);

		if (next_y_cell != curr_y && next_x_cell != curr_x)
				return (1);
// todo :: return 0;
		return (1);
}

int   get_pxl_minimap(t_window *win, int x, int y)
{
	int  bit_per_pxl;
	int  offset;
	
	bit_per_pxl = win->mini_map.bpp / 8;
	offset = y * win->mini_map.sizeline + x * bit_per_pxl;
	if (x >= win->mini_map.row * TILESIZE \
		|| y >= win->mini_map.col * TILESIZE)
		return (-1);
	else
		return (*(int *)(win->mini_map.addr + offset));
}

void  ft_pxl(t_window *w, int x, int y, int clr)
{
	char   *cordo_addr;

	if (x >= w->mini_map.row * TILESIZE \
			|| y >= w->mini_map.col * TILESIZE) 
		return ;
	cordo_addr = w->mini_map.addr \
				+ (y * w->mini_map.sizeline \
				+ x * (w->mini_map.bpp / 8));
	*(int *)cordo_addr = clr;
}

void ft_pxl_cub(t_window *w, int x, int y, int clr)
{
	char   *cordo_addr;

	if (x >= WIN_W || y >= WIN_W)
		return ;
	cordo_addr = w->addr_fps + (y * w->fps_sizeline + x * (w->fps_bpp / 8));
	*(int *)cordo_addr = clr;
}

void  ft_pxl_line(t_window *w, t_xy str, t_xy end, int clr)
{
	t_dou_xy  mid;
	t_dou_xy  dou_mid;
	double    pxline_len;

	mid.x = 0;
	mid.y = 0;
	pxline_len = sqrt(pow(end.x - str.x ,2) + pow(end.y - str.y, 2));
	dou_mid.x = (end.x - str.x) / pxline_len;
	dou_mid.y = (end.y - str.y) / pxline_len;
	while (pxline_len-- > 0)
	{
		ft_pxl(w, str.x + mid.x, str.y + mid.y, clr);
		// printf("here:%f\n", dou_mid.x);
		mid.x += dou_mid.x;
		mid.y += dou_mid.y;
	}
}

void  ft_pxl_block(t_window *w, t_xy cordo, int clr)
{
	t_xy  pos;

	pos.y = 0;
	while (pos.y < MAP_TILESIZE)
	{
		ft_pxl(w, ((cordo.x * MAP_TILESIZE) + 0), \
					((cordo.y * MAP_TILESIZE) + pos.y), 0);
		pos.x = 0;
		while (pos.x < MAP_TILESIZE)
		{
			ft_pxl(w, ((cordo.x * MAP_TILESIZE) + pos.x), \
					((cordo.y * MAP_TILESIZE) + pos.y), clr);
			pos.x++;
		}
		pos.y++;
	}
}
