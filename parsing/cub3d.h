/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:43:25 by aomman            #+#    #+#             */
/*   Updated: 2023/02/25 21:04:39 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include<fcntl.h>
# include<mlx.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>

# define WIN_W 960
# define WIN_H 540
# define P 3.14159265359
# define TILESIZE 32
# define MINIMAP_FACTOR 1
# define MAP_TILESIZE TILESIZE / MINIMAP_FACTOR
# define MAP_GRIDE_FACTOR WIN_W / (double) MINIMAP_FACTOR
# define COL_STRIP 1
# define SCALE (MAP_GRIDE_FACTOR / (double) WIN_W)
# define FOV 120

typedef struct s_var
{
	void	*wall;
	void	*floor;
	int		posx;
	int		posy;
	int		i;
	int		j;
	int		s;
	int		n;
	int		e;
	int		w;
	int		checker;
	int		fd_map;
	char	*map;
	char	**map_elmnt;
	char	*path_so;
	char	*path_no;
	char	*path_ea;
	char	*path_we;
	int		*f_colors;
	int		*c_colors;
}	t_var;

typedef struct s_ray
{
	double	hit_x;
	double	hit_y;
	int		closest_grid_x;
	int		closest_grid_y;
	double	angle;
	int		face_up;
	int		face_left;
	double	distance;
	int		projwall;
	int		wallstriphoehjt;
	int		windowsheight;
	int		is_horizontal;
}	t_ray;

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
  //t_ply     ply;
  //t_2D_map  mini_map;
  char      *addr_fps;
  int       fps_bpp;
  int       fps_endian;
  int       fps_sizeline;
  t_ray     rays[WIN_W];
} t_window;


void	ft_putstr(char *str, int fd);
void	paths_valid(t_var *var);
void	ft_find_position(t_var *var);
void	ft_draw_walls();
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strstr(char *str, char *to_find);
char	*remove_spaces_in_begin(char *str);
char	*color_adjustement(t_var *var);
char	*ft_strcpy(char *s1, char *s2);
char	*skip_spaces(char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		check_map(t_var *var, char **argv);
int		ft_arealpha(char *str);
int		valid_map_is_valid(t_var *var);
int		ft_strlen(const char *str);
int		check_spaces(char *str);
int		check_errors(t_var *var, char **argv);
int		check_errors2(t_var *var, char **argv);
int		check_texture(t_var *var);
int		ft_atoi(const char *str);
int		check_colors(t_var *var);
int		check_sky_color(t_var *var);
int		check_floor_color(t_var *var);
int		check_key_f(t_var *var);
int		check_key_c(t_var *var);
int		check_values(t_var *var);
int		check_key_f(t_var *var);
int		check_map_component(t_var *var);
int		check_numberof_element(t_var *var);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
