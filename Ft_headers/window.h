/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:48 by midfath           #+#    #+#             */
/*   Updated: 2023/02/14 11:39:03 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define  WINDOW_H 
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <libft.h>

# define WIN_W 960
# define WIN_H 540
# define mapWidth 25
# define mapHeight 21
# define TILESIZE 38
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

typedef struct s_2D_map
{
  void    *img;
  int     row;
  int     col;
  char    *addr;
  int     endian;
  int     bpp;
  int     sizeline;
} t_2D_map;

typedef struct s_window 
{
  char      **map;
  int       height;
  int       width;
  void      *mlx;
  void      *fps;
  void      *win_ptr;
  int       x;
  int       y;
  t_ply     *ply;
  t_2D_map  mini_map;
  char      *addr_fps;
  int       fps_bpp;
  int       fps_endian;
  int       fps_sizeline;
} t_window;


t_window  *init_win();
void      open_window(t_window  *win);
int       mini_map_display(t_window *win);
void      ft_put_img(t_window *w, void *img,int x, int y);
void    	ft_assign_tiles(t_window *w);
void      init_tx();
int       end_window(t_window *w);
void	    ft_mapping(t_window *w, int i, int j);
 
#endif // !WINDOW_H
