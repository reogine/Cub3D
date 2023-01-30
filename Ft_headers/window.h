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
# define 
# include <stdio.h>
# include <mlx.h>
 
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define tileSize 32;


typedef struct s_ply
{
  int x;
  int y;
  char  dir;
  
} t_ply;

typedef struct t_window 
{
  char      **map;
  int       height;
  int       width;
  void      *mlx;
  void      *win_ptr;
  int       x;
  int       y;
  t_player  p;
};

void  open_window(t_window  *win);

#endif // !WINDOW_h

