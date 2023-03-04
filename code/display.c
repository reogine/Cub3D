/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/03/02 23:50:47 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/cub3d.h"
#include <window.h>

void	render_frame(t_window *w)
{
	rays_calc(w);
	wall_text(w);
	ft_draw_walls(w);
	render_minimap(w);
}

void	open_window(t_window *win)
{
	render_frame(win);
	mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0);
		//   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
	mlx_hook(win->win_ptr, 17, 0, end_window, win);
	mlx_hook(win->win_ptr, 2, 0, trigger_key, win);
	mlx_loop(win->mlx);
}

int	trigger_key(int key, t_window *win)
{
	if (key == KEY_W)
		ft_go_up(win);
	else if (key == KEY_S)
		ft_go_down(win);
	else if (key == KEY_A)
		ft_go_right(win);
	else if (key == KEY_D)
		ft_go_left(win);
	if (key == KEY_RIGHT)
		win->ply.rot_ang += 4 * (P / 180);
	else if (key == KEY_LEFT)
		win->ply.rot_ang -= 4 * (P / 180);
	if (win->ply.rot_ang < 0)
		win->ply.rot_ang += 2 * P;
	else if (win->ply.rot_ang > 2 * P)
		win->ply.rot_ang -= 2 * P;
	rays_calc(win);
	ft_draw_walls(win);
	render_minimap(win);
	mlx_put_image_to_window(win->mlx, win->win_ptr, win->fps, 0, 0);
		//   mlx_loop_hook(win->mlx, key_pressed, (void *)win);
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	end_window(t_window *win)
{
	// ft_matfreex(&win->map);
	// mlx_destroy_window(win->mlx, win->win_ptr);
	// free(win->mlx);
	(void)win;
	exit(0);
}
