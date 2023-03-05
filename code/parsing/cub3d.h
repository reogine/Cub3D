/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:43:25 by aomman            #+#    #+#             */
/*   Updated: 2023/03/03 19:37:27 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../Ft_headers/game_dev.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void		ft_putstr(char *str, int fd);
void		paths_valid(t_var *var);
void		ft_find_position(t_var *var);
void		ft_draw_walls(t_window *win);
int			map_lines(char **map);
char		*get_next_line(int fd);
char		*ft_strstr(char *str, char *to_find);
char		*remove_spaces_in_begin(char *str);
char		*color_adjustement(char *str);
char		*ft_strcpy(char *s1, char *s2);
char		*skip_spaces(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			check_map(t_var *var, char **argv);
int			ft_arealpha(char *str);
int			valid_map_is_valid(t_var *var);
int			check_spaces(char *str);
int			check_errors(t_var *var, char **argv);
int			check_errors2(t_var *var, char **argv);
int			check_texture(t_var *var);
int			check_colors(t_var *var);
int			check_sky_color(t_var *var, char *str);
int			check_floor_color(t_var *var, char *str);
int			check_key_f(t_var *var);
int			check_key_c(t_var *var);
int			check_values(t_var *var);
int			check_map_component(t_var *var);
int			check_numberof_element(t_var *var);
int			rgb_to_hex(int *color);
int			wall_text(t_window *win);
int			set_floor_color(t_var *var, char **color_elmnt);
int			rgb_to_hex(int *color);

#endif
