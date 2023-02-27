/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:48 by midfath           #+#    #+#             */
/*   Updated: 2023/02/27 16:33:30 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define  WINDOW_H 
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <libft.h>
# include <math.h>

# define FOV 60
# define WIN_W 960
# define WIN_H 540
# define P 3.14159265359
# define TILESIZE 32
# define MINIMAP_FACTOR 1
# define MAP_TILESIZE TILESIZE / MINIMAP_FACTOR
# define MAP_GRIDE_FACTOR WIN_W / (double) MINIMAP_FACTOR
# define COL_STRIP 1
# define SCALE (MAP_GRIDE_FACTOR / (double) WIN_W)

/*player size*/
# define SIZE MAP_TILESIZE / 4

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


typedef struct s_ray
{
	double  hit_x;             // x-coordinate of the point where the ray hit a wall
	double  hit_y;             // y-coordinate of the point where the ray hit a wall
	int     closest_grid_x;       // x-coordinate of the closest grid intersection
	int     closest_grid_y;       // y-coordinate of the closest grid intersection
	double  angle;             // angle of the ray (in radians)
	int     face_up;              // flag indicating if the ray is facing up
	int     face_left;            // flag indicating if the ray is facing left
	double  distance;          // distance from the player to the wall hit by the ray
	int     is_horizontal;        // flag indicating if the ray is horizontal
} t_ray;

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

typedef struct s_dou_xy
{
 int x;
 int y;
} t_dou_xy;


typedef struct s_xy
{
 int x;
 int y;
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
  t_ply     ply;
  t_2D_map  mini_map;
  char      *addr_fps;
  int       fps_bpp;
  int       fps_endian;
  int       fps_sizeline;
  t_ray     rays[WIN_W];
} t_window;


t_window  *init_win();
void      open_window(t_window  *win);
void      mini_map_overlay(t_window *win);
void      mini_map_display(t_window *win);
void    	render_frame(t_window *w);
void      render_minimap(t_window *w);
void    	ft_assign_tiles(t_window *w);
void      init_tx();
int       end_window(t_window *w);
void	    ft_mapping(t_window *w, int i, int j);
void      ft_pxl_cub(t_window *w, int x, int y, int clr);
void      ft_pxl(t_window *w, int x, int y, int clr);
void      ft_pxl_strip(t_window *w, t_xy str, t_xy end, int clr);
void      ft_pxl_block(t_window *w, t_xy cordo, int clr);
int       get_pxl_minimap(t_window *win, int x, int y);
void      rays_display(t_window *win);
void      ray_hit(t_window  *win, double rot_ang, int indx);
void      rays_calc(t_window *win);
t_dou_xy  find_hit_point(t_window *win,t_ray *ray, int is_hor);
void      calc_hor_line(t_window *win, t_dou_xy *hit, t_ray *ray);
void      calc_ver_line(t_window *win, t_dou_xy *hit, t_ray *ray);

/* Player */
void      init_ply(t_window *win);
void      get_ply_cordo(t_window *win, t_xy cordo);
void      ply_display(t_window *win);

#endif // !WINDOW_H
