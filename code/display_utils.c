/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:11:24 by midfath           #+#    #+#             */
/*   Updated: 2023/02/23 01:40:12 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

int   get_pxl_minimap(t_window *win, int x, int y)
{
  int  bit_per_pxl;
  int  offset;
  
  bit_per_pxl = win->mini_map.bpp / 8;
  offset = y * win->mini_map.sizeline + x * bit_per_pxl;
  if (x >= win->mini_map.row * TILESIZE \
    || y >= win->mini_map.col * TILESIZE)
    return (0xf5f5dc);
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
  cordo_addr = w->addr_fps\
        + (y * w->fps_sizeline \
        + x * (w->fps_bpp / 8));
  *(int *)cordo_addr = clr;
}

void  ft_pxl_strip(t_window *w, t_xy str, t_xy end, int clr)
{
  t_xy    delta;
  double  pxline_len;
  t_xy    step;
  t_xy    current;
  delta.x = end.x - str.x;
  delta.y = end.y - str.y;
  pxline_len = sqrt(delta.x * delta.x + delta.y * delta.y);
  step.x = delta.x / pxline_len;
  step.y = delta.y / pxline_len;
  current = str;
  while (pxline_len > 0)
  { 
    ft_pxl(w, current.x, current.y, clr);
    current.x += (int)round(step.x);
    current.y += (int)round(step.y); 
    pxline_len -= 1;
  }
  ft_pxl(w, end.x, end.y, clr);
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
