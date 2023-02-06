/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:20 by midfath           #+#    #+#             */
/*   Updated: 2023/02/06 17:51:43 by midfath          ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include <window.h>

// void  square(t_window win, t_xy cordo)
// {

// }

t_window *init_win()
{
  t_window  *win;


  init_tileset();
  win = (t_window *)malloc(sizeof(t_window));
  win->ply = (t_ply *)malloc(sizeof(t_ply)); 
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
  mini_map_display(win);
  // i = 0;

  mlx_loop(win->mlx);
}

void  mini_map_display(t_window *win) 
{
  t_xy  cordo;
  t_xy  end;

  while (win->map[][])
    {
      // square(win, cordo); 

    }
}

void	ft_mapping(t_window *w, int i, int j)
    mlx_put_image_to_window(w->id, w->w_id, w->tileset.wall \
                            , i * SIZE, j * SIZE);
  else if (w->map[j][i] == 'C')
      mlx_put_image_to_window(w->id, w->w_id, w->tileset.coin \
                              , i * SIZE, j * SIZE);
  else if (w->map[j][i] == 'E')
      mlx_put_image_to_window(w->id, w->w_id, w->tileset.door \
                                , i * SIZE, j * SIZE);
  else if (w->map[j][i] == '0')
      mlx_put_image_to_window(w->id, w->w_id, w->tileset.terrain \
                                  , i * SIZE, j * SIZE);
}
