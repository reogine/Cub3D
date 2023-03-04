/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/03/04 13:13:10 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	render_frame(t_window *win)
{
  rays_calc(win);
  render_minimap(win); 
}

void  open_window(t_window  *win)
{
  render_frame(win);
  mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0); //   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
  mlx_mouse_hide(win->win_ptr);
  mlx_hook(win->win_ptr, 17, 0, end_window, win);
  mlx_hook(win->win_ptr, 2, 0, trigger_key, win);
  mlx_hook(win->win_ptr, 6, 0, trigger_mouse, win);
  mlx_loop(win->mlx);
}

int  trigger_mouse(int x, int y, t_window *win)
{
  (void)y;
  mlx_mouse_move(win->win_ptr, (WIN_W / 2), (WIN_H / 2));
  if (x - (WIN_W / 2) < 0)
    win->ply.rot_ang -= 4 * (P / 180);
  else if (x - (WIN_W / 2) > 0)
    win->ply.rot_ang += 4 * (P / 180);
  if (win->ply.rot_ang < 0)
    win->ply.rot_ang += 2 * P;
  else if (win->ply.rot_ang > 2 * P)
    win->ply.rot_ang -= 2 * P;
  rays_calc(win);
  render_minimap(win); 
  mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0); //   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
	return (0);
}


int	trigger_key(int key, t_window *win)
{
  if (key == KEY_W)
		ft_go_up(win);
	else if (key == KEY_S) 
		ft_go_down(win); 
  else if (key == KEY_D) 
		ft_go_right(win);
	else if (key == KEY_A)
		ft_go_left(win);
  if (key == KEY_RIGHT)
    win->ply.rot_ang += 5 * (P / 180);
  else if (key == KEY_LEFT)
    win->ply.rot_ang -= 5 * (P / 180);
  if (win->ply.rot_ang < 0)
    win->ply.rot_ang += 2 * P;
  else if (win->ply.rot_ang > 2 * P)
    win->ply.rot_ang -= 2 * P;
  rays_calc(win);
  render_minimap(win); 
  mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0);
  if (key == KEY_ESC)
		exit (0);
	return (0);
}


int	end_window(t_window *win)
{
  ft_matfreex(&win->map);
	mlx_destroy_window(win->mlx, win->win_ptr);
	exit (0);
}
