/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/02/11 13:58:54 by midfath          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include <window.h>

void  ft_pxl(t_window win, int x, int y, int clr)
{
  char *pos;

  if (x < 0 || x >= win->width)
} 
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
  win->height = (mapWidth * TILESIZE); 
  win->width = (mapHeight * TILESIZE);
  win->win_ptr = mlx_new_window(win->mlx, win->height, win->width, "game");
  win->map = ft_split(map, ',')/* ft_matrdupix(map) */;
  ft_assign_tiles(win);
  return (win);
}

void  open_window(t_window  *win)
{
  // mini_map_display(win);
  // i = 0;
//   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
  mlx_loop_hook(win->mlx, mini_map_display, (void *)win);
  // mlx_hook(win->mlx, 17, 0, end_window, (void *)win);
  mlx_loop(win->mlx);
}

int mini_map_display(t_window *win)
{
  int   i;
  int   j;
  // t_xy  cordo;
  // t_xy  end;

  i = 0;
  j = 0;

  return (0);
}

void	ft_mapping(t_window *w, int i, int j)
{
  if (w->map[j][i] == '1')  
  mlx_put_image_to_window(w->mlx, w->win_ptr, w->tileset.wall \
                            , i * SIZE, j * SIZE);
  // else if (w->map[j][i] == 'C')
  //     mlx_put_image_to_window(w->mlx, w->win_ptr, w->tileset.coin \
  //                             , i * SIZE, j * SIZE);
  // else if (w->map[j][i] == 'E')
  //     mlx_put_image_to_window(w->mlx, w->win_ptr, w->tileset.door \
  //                               , i * SIZE, j * SIZE);
  else if (w->map[j][i] == '0')
      mlx_put_image_to_window(w->mlx, w->win_ptr, w->tileset.terain \
                                  , i * SIZE, j * SIZE);
}
