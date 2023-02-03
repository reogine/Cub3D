/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/02/03 00:44:15 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

t_window *init_win()
{
  t_window  *win;


  win = (t_window *)malloc(sizeof(t_window));
  win->p = (t_ply *)malloc(sizeof(t_ply)); 
  // init_ply(win->p);
  win->x = 0;
  win->y = 0;
  win->mlx = mlx_init();
  win->height = (mapWidth * tileSize); 
  win->width = (mapHeight * tileSize);
  win->win_ptr = mlx_new_window(win->mlx, win->height, win->width, "game");
  win->map = NULL;

  return (win);
}

void  open_window(t_window  *win)
{
 // int  i;

  // i = 0;
  mlx_loop(win->mlx);
}
