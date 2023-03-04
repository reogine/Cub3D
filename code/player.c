/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:19:04 by midfath           #+#    #+#             */
/*   Updated: 2023/03/04 09:23:32 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void  get_ply_cordo(t_window *win, t_xy cordo)
{
  win->ply.x = (cordo.x * TILESIZE) + TILESIZE / 2;
  win->ply.y = (cordo.y * TILESIZE) + TILESIZE / 2; 
  if (win->map[cordo.y][cordo.x] == 'N')
    win->ply.rot_ang = (3 * P) / 2;
  else if (win->map[cordo.y][cordo.x] == 'W')
    win->ply.rot_ang = P;
  else if (win->map[cordo.y][cordo.x] == 'S')
    win->ply.rot_ang = P / 2;
  else if (win->map[cordo.y][cordo.x] == 'E')
    win->ply.rot_ang = 0;
}

void init_ply(t_window *win)
{
   t_xy cordo;

  cordo.y = 0;
  while (win->map[cordo.y])
  {
    cordo.x = 0;
    while (win->map[cordo.y][cordo.x])
    {
      if (ft_strchr("NSEW", win->map[cordo.y][cordo.x]))
      {
        get_ply_cordo(win, cordo);
        win->map[cordo.y][cordo.x] = '0';
        return; 
      }
      cordo.x++;
    }
    cordo.y++;
  }
  if (!win->map[cordo.y])
    exit (write(2, "errror player not found\n", 14));
}

void  ply_display(t_window *win)
{
  t_xy  ply_cordo;

  ply_cordo.y = (SIZE * -1) + (SIZE / 2);
  while (ply_cordo.y < 4) 
  {
    ply_cordo.x = (SIZE * -1) + (SIZE / 2);
    while (ply_cordo.x < 4)
    {
      ft_pxl(win, (ply_cordo.x + ( win->ply.x * SCALE)),
         (ply_cordo.y + (win->ply.y * SCALE)), 0xf5f5dc);
      ply_cordo.x++;
    }
    ply_cordo.y++;
  }
}
