/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/01/30 10:03:45 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void init_win(t_window *win)
{
  win->x = 0;
  win->y = 0;
  win->mlx = mlx_init();
  win->height = screenHeight*tileSize;
  win->width = screenWidth*tileSize;
  win->win_ptr = NULL;
  win->map = NULL;
}

void  open_window(t_window  *win)
{
  
}
