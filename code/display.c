/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/03/01 18:58:23 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include "parsing/cub3d.h"

void	render_frame(t_window *w)
{
  rays_calc(w);
  ft_draw_walls(w);
  render_minimap(w); 
}

void  open_window(t_window  *win)
{
  render_frame(win);
  mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0); //   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
  mlx_hook(win->win_ptr, 17, 0, end_window, win);
  mlx_hook(win->win_ptr, 2, 0, trigger_key, win);
  mlx_loop(win->mlx);
}

int	trigger_key(int key, t_window *win)
{
  if (key == KEY_W)
		ft_go_up(key, win);
	// else if (key == KEY_S || key == KEY_DOWN) 
		// ft_go_down(w);
	// else if (key == KEY_A 
  if (key == KEY_RIGHT)
    win->ply.rot_ang += 4 * (P / 180);
  else if (key == KEY_LEFT)
    win->ply.rot_ang -= 4 * (P / 180);
		// ft_go_right(w);
	// else if (key == KEY_D || key == KEY_RIGHT)
		// ft_go_left(w);
  rays_calc(win);
  render_minimap(win); 
  mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0); //   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
	if (key == KEY_ESC)
		exit (0);
	return (0);
}


int	end_window(t_window *w)
{
	 // ft_matfreex(&win->map);
	// mlx_destroy_window(win->mlx, win->win_ptr);
  // free(win->mlx);
	(void) w;	
	exit (0);
}
