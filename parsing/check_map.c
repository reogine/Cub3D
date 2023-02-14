/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:01:55 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 19:01:56 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_map(t_var *var, char **argv)
{
	char	*map_ext;

	map_ext = ft_strrchr(argv[1], '.');
	if (map_ext == NULL)
		return (1);
	if (ft_strcmp(map_ext, ".cub") != 0)
	{
		ft_putstr("map must be .cub extention\n", 2);
		return (1);
	}
	var->fd_map = open (argv[1], O_RDONLY, 600);
	if (var->fd_map < 0)
	{
		ft_putstr("Error in map fd", 2);
		close(var->fd_map);
		return (1);
	}
	var->map = get_next_line(var->fd_map);
	if (var->map == NULL)
	{
		ft_putstr("map must have valid component\n", 2);
		return (1);
	}
	close(var->fd_map);
	return (0);
}

int	check_so_no(char *str, t_var *var)
{
	if (ft_strstr(var->map_elmnt[var->i], "SO") != NULL)
	{
		str = ft_strstr(var->map_elmnt[var->i], "SO");
		var->path_so = ft_strchr(str, '.');
	}
	if (ft_strstr(var->map_elmnt[var->i], "NO") != NULL)
	{
		str = ft_strstr(var->map_elmnt[var->i], "NO");
		var->path_no = ft_strchr(str, '.');
	}
	return (0);
}

void	check_ea_we(char *str, t_var *var)
{
	if (ft_strstr(var->map_elmnt[var->i], "EA") != NULL)
	{
		str = ft_strstr(var->map_elmnt[var->i], "EA");
		var->path_ea = ft_strchr(str, '.');
	}
	if (ft_strstr(var->map_elmnt[var->i], "WE") != NULL)
	{
		str = ft_strstr(var->map_elmnt[var->i], "WE");
		var->path_we = ft_strchr(str, '.');
	}
}

char	*chaeck_xpm(char *str, t_var *var)
{
	if (!str || ft_strcmp(str, ".xpm") != 0)
		return (NULL);
	check_so_no(str, var);
	check_ea_we(str, var);
	return (str);
}

void	paths_valid(t_var *var)
{
	char	*xpm;
	char	*valid_paths;

	var->map_elmnt = ft_split(var->map, '\n');
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		xpm = ft_strrchr(var->map_elmnt[var->i], '.');
		if (!xpm)
			return ;
		valid_paths = chaeck_xpm(xpm, var);
		if (!valid_paths)
			return ;
		var->i++;
	}
	return ;
}
