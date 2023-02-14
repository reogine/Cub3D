/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/02/14 11:40:01 by midfath          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include <window.h>

// void  ft_pxl(t_window win, int x, int y, int clr)
// {
//   char *pos;

//   if (x < 0 || x >= win->width)
//    return ; 
//   pos = win->
// }
// void  square(t_window win, t_xy cordo)
// {

// }

t_window *init_win()
{
  t_window  *win;

  char  map[]="11111111111111111111111111,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
10000000000000000000000001,\
11111111111111111111111111"
;


  // init_tx(win);
  win = (t_window *)malloc(sizeof(t_window));
  win->ply = (t_ply *)malloc(sizeof(t_ply)); 
  // init_ply(win->p);
  win->x = 0;
  win->y = 0;
  win->mlx = mlx_init();
  win->height = WIN_H; 
  win->width = WIN_W;
  win->win_ptr = mlx_new_window(win->mlx, win->width, win->height, "game");
  win->map = ft_split(map, ',')/* ft_matrdupix(map) */;
  win->fps = mlx_new_image(win->mlx, win->width, win->height);
  win->addr_fps = mlx_get_addr(win->fps, &win->fps_bpp, \
         &win->fps_sizeline, &win->fps_endian);
  win->mini_map.img = mlx_new_image(win->mlx, \
         win->mini_map.row * TIlESIZE, win->mini_map.col * TIlESIZE);
  win->mini_map.addr = mlx_get_addr(win->mini_map.img, &win->mini_map.bpp \
         &win->mini_map.sizeline, &win->mini_map.endian);
  win->mini_map.row = ft_strlen(win->map[0]);
  win->mini_map.col = 25;
  return (win);
}

void  open_window(t_window  *win)
{
  // mini_map_display(win);
  // i = 0;
//   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
  // mlx_loop_hook(win->mlx, mini_map_display, (void *)win);
  // mlx_hook(win->mlx, 17, 0, end_window, (void *)win);
  // mini_map_display(win);
  mlx_loop(win->mlx);
}

// int mini_map_display(t_window *win)
// {
//   // int   i;
//   // int   j;
//   // // t_xy  cordo;
//   // // t_xy  end;

//   // i = 0;
//   // j = 0;

//   return (0);
// }

