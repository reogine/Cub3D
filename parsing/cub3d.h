/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:43:25 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 18:43:27 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include<fcntl.h>
# include<mlx.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

typedef struct s_var
{
	int		i;
	int		j;
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

void	ft_putstr(char *str, int fd);
void	paths_valid(t_var *var);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strstr(char *str, char *to_find);
char	*remove_spaces_in_begin(char *str);
char	*color_adjustement(t_var *var);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		check_map(t_var *var, char **argv);
int		ft_arealpha(char *str);
int		valid_map_is_valid(t_var *var);
int		ft_strlen(const char *str);
int		check_spaces(char *str);
int		check_errors(t_var *var, char **argv);
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

#endif
