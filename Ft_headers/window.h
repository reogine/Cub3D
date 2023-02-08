/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:48 by midfath           #+#    #+#             */
/*   Updated: 2023/02/08 03:51:03 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define  WINDOW_H 
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <libft.h>

#define mapWidth 25
#define mapHeight 25
#define TILESIZE 38
/*images size*/
# define SIZE 38
# define COL_STRIP 1
/*Key Codes :*/
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124


char  map[25][25]={
  "111111111111111111111111",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "111111111111111111111111",
};

typedef struct s_texs
{
	void	*add;
	void	*img;
	int		h_texs;
	int		w_texs;
	int		pxl_strip;
}t_texs;


typedef struct s_ply
{
  double x;
  double y;
  double  rot_ang;
  
} t_ply;

typedef struct s_xy
{
 double x;
 double y;
} t_xy;

typedef struct s_tileset
{
  void  *wall;
  void  *terain;
} t_tileset;

typedef struct s_window 
{
  char      **map;
  int       height;
  int       width;
  void      *mlx;
  void      *win_ptr;
  int       x;
  int       y;
  t_ply     *ply;
  t_tileset tileset;
} t_window;


t_window  *init_win();
void      open_window(t_window  *win);
int       mini_map_display(t_window win);
void      ft_put_img(t_window *w, void *img,int x, int y);
t_tileset	ft_assign_tx(t_window *w);
void      init_tx();
int       end_window(t_window *w);
void	    ft_mapping(t_window *w, int i, int j);
 
#endif // !WINDOW_H
