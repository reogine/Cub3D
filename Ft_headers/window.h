/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:48 by midfath           #+#    #+#             */
/*   Updated: 2023/02/01 17:25:37 by mostapha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define  WINDOW_H 
# include <stdio.h>
# include <mlx.h>
#include <stdlib.h>

#define mapWidth 24
#define mapHeight 24
#define tileSize 32

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
  // t_ply     *p;
} t_window;

t_window  *init_win();
void  open_window(t_window  *win);

#endif // !WINDOW_H

