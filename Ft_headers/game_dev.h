/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_dev.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:43:26 by aomman            #+#    #+#             */
/*   Updated: 2023/03/02 00:43:29 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DEV_H
# define GAME_DEV_H

# include <libft.h>

# define PPM 10
# define FOV 60
# define WIN_W 800
# define WIN_H 600
# define P 3.14159265359
# define TILESIZE 32
# define MINIMAP_FACTOR 1
# define MAP_TILESIZE TILESIZE / MINIMAP_FACTOR
# define MAP_GRIDE_FACTOR WIN_W / (double)MINIMAP_FACTOR
# define COL_STRIP 1
# define SCALE (MAP_GRIDE_FACTOR / (double)WIN_W)
# define TEX_H 32
# define TEX_W 32

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

typedef struct s_var
{
	void		*wall;
	void		*mlx_win;
	void		*mlx;
	void		*floor;
	int			posx;
	int			posy;
	int			i;
	int			j;
	int			s;
	int			n;
	int			e;
	int			w;
	int			offset;
	int			top_p;
	int			down_p;
	int			checker;
	int			fd_map;
	int			dst;
	char		*map;
	char		**map_elmnt;
	char		*path_so;
	char		*path_no;
	char		*path_ea;
	char		*path_we;
	int			*c_colors;
	int			*f_colors;
}				t_var;
typedef struct s_ray
{
	double		hit_x;
	double		hit_y;
	int			closest_grid_x;
	int			closest_grid_y;
	double		angle;
	int			face_up;
	int			face_left;
	double		distance;
	double		corr_d;
	int			projwall;
	int			wallstriphiehgt;
	int			windowsheight;
	int			is_horizontal;
	int			top_p;
	int			down_p;
}				t_ray;

typedef struct s_texs
{
	void		*add;
	void		*img;
	int			h_texs;
	int			w_texs;
	int			pxl_strip;
}				t_texs;

typedef struct s_ply
{
	double		x;
	double		y;
	double		rot_ang;

}				t_ply;

typedef struct s_dou_xy
{
	double		x;
	double		y;
}				t_dou_xy;

typedef struct s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct s_2D_map
{
	void		*img;
	int			row;
	int			col;
	char		*addr;
	int			endian;
	int			bpp;
	int			sizeline;
}				t_2D_map;

typedef struct s_window
{
	char		**map;
	int			height;
	int			*f_colors;
	int			*c_colors;
	int			width;
	void		*mlx;
	void		*fps;
	void		*win_ptr;
	int			x;
	int			y;
	t_ply		ply;
	t_2D_map	mini_map;
	char		*addr_fps;
	int			fps_bpp;
	int			fps_endian;
	int			fps_sizeline;
	void		*so_text;
	void		*no_text;
	void		*we_text;
	void		*ea_text;
	char		*so_addr;
	char		*no_addr;
	char		*ea_addr;
	char		*we_addr;
	char		*path_so;
	char		*path_no;
	char		*path_ea;
	char		*path_we;
	t_ray		rays[WIN_W];
}				t_window;

#endif // GAME_DEV_H
