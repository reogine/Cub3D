/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:48 by midfath           #+#    #+#             */
/*   Updated: 2023/01/30 09:18:58 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define  WINDOW_H 
# include <stdio.h>
# include <mlx.h>
 
#define mapWidth 24
#define mapHeight 24
#define screenWidth (mapWidth * tileSize) 
#define screenHeight (mapHeight * tileSize) 
#define tileSize 32;

typedef struct s_ply
{
  float x;
  float y;
  float  rot_ang;
  
} t_ply;

typedef struct s_window 
{
  char      **map;
  int       height;
  int       width;
  void      *mlx;
  void      *win_ptr;
  int       x;
  int       y;
  t_ply     *p;
} t_window;

void  init_win(t_window *win);
void  open_window(t_window  *win);

#endif // !WINDOW_H

