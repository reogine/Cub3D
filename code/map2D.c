/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/02/01 17:20:41by mostapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void init_win(t_window *win)
{
  win->x = 0;
  win->y = 0;
  win->mlx = mlx_init();
  win->height = (mapWidth * tileSize); 
  win->width = (mapHeight * tileSize);
  win->win_ptr = NULL;
  win->map = NULL;
}

void  open_window(t_window  *win)
{
  win->win_ptr = mlx_new_window(win->mlx, win->width, win->height, "game");
}
