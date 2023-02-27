/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/02/27 16:57:30 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	render_frame(t_window *w)
{
  rays_calc(w);
  render_minimap(w); 
}

void  open_window(t_window  *win)
{
  render_frame(win);
  mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0);
//   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
  // mlx_hook(win->mlx, 17, 0, end_window, win);
  mlx_loop(win->mlx);
}

int	key_pressed(int key, t_window *w)
{
	// if ((key == KEY_W || key == KEY_UP)) 
		// ft_go_up(w);
	// else if (key == KEY_S || key == KEY_DOWN) 
		// ft_go_down(w);
	// else if (key == KEY_A || key == KEY_LEFT)
		// ft_go_right(w);
	// else if (key == KEY_D || key == KEY_RIGHT)
		// ft_go_left(w);
	if (key == KEY_ESC)
		end_window(w);
	return (0);
}


int	end_window(t_window *w)
{
	 // ft_matfreex(&win->map);
	// mlx_destroy_window(win->mlx, win->win_ptr);
  // free(win->mlx);
	if (w)	
	exit (0);
	return 0;
}
