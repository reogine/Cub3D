/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:25:22 by midfath           #+#    #+#             */
/*   Updated: 2023/03/03 13:24:11 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

static int	check_hit(t_window *w, double nxt_x, double nxt_y, int is_ver)
{
	t_xy	nxt_pos;
	char	*nxt_cell;
	char	*adj_cell;
	char	*ex_cell;
	char	*ex_adj_cell;

	nxt_pos.x = nxt_x;
	nxt_pos.y = nxt_y;
	if (is_ver)
	{
		nxt_cell = &w->map[(int)(w->ply.y / TILESIZE)][(int)(w->ply.x
				/ TILESIZE) + 1];
		adj_cell = &w->map[(int)(w->ply.y / TILESIZE) - 1][(int)(w->ply.x
				/ TILESIZE)];
		ex_cell = &w->map[(int)(nxt_y / TILESIZE)][(int)(nxt_x / TILESIZE) - 1];
		ex_adj_cell = &w->map[(int)(nxt_y / TILESIZE) + 1][(int)(nxt_x
				/ TILESIZE)];
	}
	else
	{
		nxt_cell = &w->map[(int)(w->ply.y / TILESIZE)][(int)(w->ply.x
				/ TILESIZE) + 1];
		adj_cell = &w->map[(int)(w->ply.y / TILESIZE) + 1][(int)(w->ply.x
				/ TILESIZE)];
		ex_cell = &w->map[(int)(nxt_y / TILESIZE)][(int)(nxt_x / TILESIZE) - 1];
		ex_adj_cell = &w->map[(int)(nxt_y / TILESIZE) - 1][(int)(nxt_x
				/ TILESIZE)];
	}
	return (*adj_cell == '1' && *nxt_cell == '1' && adj_cell == ex_cell
		&& nxt_cell == ex_adj_cell);
}

int	valid_des(t_window *w, double nxt_x, double nxt_y)
{
	int	curr_y;
	int	curr_x;
	int	next_y_cell;
	int	next_x_cell;

	curr_y = (int)(w->ply.y / TILESIZE);
	curr_x = (int)(w->ply.x / TILESIZE);
	next_y_cell = (int)(nxt_y / TILESIZE);
	next_x_cell = (int)(nxt_x / TILESIZE);
	// if (w->map[next_y_cell][next_x_cell] == '0'
	// && &w->map[curr_y][curr_x] != &w->map[next_y_cell][next_x_cell])
	// {
	if (check_hit(w, nxt_x, nxt_y, 1) || check_hit(w, nxt_x, nxt_y, 0))
		return (0);
	// }
	if (w->map[next_y_cell][next_x_cell] != '0')
		return (2);
	if (next_y_cell != curr_y && next_x_cell != curr_x)
		return (1);
	return (1);
}
