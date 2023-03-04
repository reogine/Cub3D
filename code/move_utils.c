/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:25:22 by midfath           #+#    #+#             */
/*   Updated: 2023/03/04 10:45:15 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

static int check_hit_ver(t_window *w, double nxt_x, double nxt_y)
{
  char  *nxt_cell;
  char  *adj_cell;
  char  *ex_cell;
  char  *ex_adj_cell;

  nxt_cell = &w->map[(int)(w->ply.y / TILESIZE)][(int)(w->ply.x / TILESIZE) + 1];
  adj_cell = &w->map[(int)(w->ply.y / TILESIZE) - 1][(int)(w->ply.x / TILESIZE)];
  ex_cell = &w->map[(int)(nxt_y / TILESIZE)][(int)(nxt_x / TILESIZE) - 1];
  ex_adj_cell = &w->map[(int)(nxt_y / TILESIZE) + 1][(int)(nxt_x / TILESIZE)];
  if (!(*adj_cell == '1' && *nxt_cell == '1' && adj_cell == ex_cell && nxt_cell == ex_adj_cell))
  {
    nxt_cell = &w->map[(int)(w->ply.y / TILESIZE)][(int)(w->ply.x / TILESIZE) - 1];
    ex_cell = &w->map[(int)(nxt_y / TILESIZE)][(int)(nxt_x / TILESIZE) + 1];
  }
  return (*adj_cell == '1' && *nxt_cell == '1' && adj_cell == ex_cell && nxt_cell == ex_adj_cell);
}

static int check_hit_hor(t_window *w, double nxt_x, double nxt_y)
{
  char  *nxt_cell;
  char  *adj_cell;
  char  *ex_cell;
  char  *ex_adj_cell;

  nxt_cell = &w->map[(int)(w->ply.y / TILESIZE)][(int)(w->ply.x / TILESIZE) + 1];
  adj_cell = &w->map[(int)(w->ply.y / TILESIZE) + 1][(int)(w->ply.x / TILESIZE)];
  ex_cell = &w->map[(int)(nxt_y / TILESIZE)][(int)(nxt_x / TILESIZE) - 1];
  ex_adj_cell = &w->map[(int)(nxt_y / TILESIZE) - 1][(int)(nxt_x / TILESIZE)];
  if (!(*adj_cell == '1' && *nxt_cell == '1' && adj_cell == ex_cell && nxt_cell == ex_adj_cell))
  {
    nxt_cell = &w->map[(int)(w->ply.y / TILESIZE)][(int)(w->ply.x / TILESIZE) - 1];
    ex_cell = &w->map[(int)(nxt_y / TILESIZE)][(int)(nxt_x / TILESIZE) + 1];
  }
  return (*adj_cell == '1' && *nxt_cell == '1' && adj_cell == ex_cell && nxt_cell == ex_adj_cell);
}


int   valid_des(t_window *w, double nxt_x, double nxt_y)
{
  int curr_y = (int)(w->ply.y / TILESIZE);
  int curr_x = (int)(w->ply.x / TILESIZE);
  int next_y_cell = (int)(nxt_y / TILESIZE);
  int next_x_cell = (int)(nxt_x / TILESIZE);

  if (check_hit_ver(w, nxt_x, nxt_y) || check_hit_hor(w, nxt_x, nxt_y))
    return (0);
  else if (w->map[next_y_cell][next_x_cell] != '0')
      return (2);
    else if (next_y_cell != curr_y && next_x_cell != curr_x)
        return (1);
  return (1);
}
