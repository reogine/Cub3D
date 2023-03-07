/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:48 by midfath           #+#    #+#             */
/*   Updated: 2023/03/04 10:52:39 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "game_dev.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

t_window	*init_win(t_var *var);
int			open_window(t_window *win);
void		mini_map_overlay(t_window *win);
void		mini_map_display(t_window *win);
int			render_frame(t_window *w);
void		render_minimap(t_window *w);
void		init_tx(void);
int			trigger_key(int key, t_window *w);
int			end_window(t_window *w);
void		ft_pxl_cub(t_window *w, int x, int y, int clr);
void		ft_pxl(t_window *w, int x, int y, int clr);
void		ft_pxl_line(t_window *w, t_xy str, t_xy end, int clr);
void		ft_pxl_block(t_window *w, t_xy cordo, int clr);
int			get_pxl_minimap(t_window *win, int x, int y);
void		rays_display(t_window *win);
void		ray_hit(t_window *win, double rot_ang, int indx);
void		rays_calc(t_window *win);
t_dou_xy	find_hit_point(t_window *win, t_ray *ray, int is_hor);
void		calc_hor_line(t_window *win, t_dou_xy *hit, t_ray *ray);
void		calc_ver_line(t_window *win, t_dou_xy *hit, t_ray *ray);
int			trigger_mouse(int x, int y, t_window *win);

/* Player */
void		init_ply(t_window *win);
void		get_ply_cordo(t_window *win, t_xy cordo);
void		ply_display(t_window *win);
void		ft_go_left(t_window *w);
void		ft_go_right(t_window *w);
void		ft_go_down(t_window *w);
void		ft_go_up(t_window *w);
int			valid_des(t_window *w, double nxt_x, double nxt_y);

#endif // !WINDOW_H
