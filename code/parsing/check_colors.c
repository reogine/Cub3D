/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:16:34 by aomman            #+#    #+#             */
/*   Updated: 2023/03/07 10:29:50 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

static	void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	set_floor_color(t_var *var, char **color_elmnt)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color_elmnt[i] == NULL)
			return (1);
		var->f_colors[i] = ft_atoi(color_elmnt[i]);
		i++;
	}
	if (color_elmnt)
		ft_free(color_elmnt);
	return (0);
}

int	check_floor_color(t_var *var, char *str)
{
	char	*color;
	char	**color_elmnt;

	var->f_colors = malloc(sizeof(int) * 3);
	str = remove_spaces_in_begin(str);
	if (check_key_f(var) == 1)
		return (1);
	color = color_adjustement(str);
	if (color == NULL || !var->f_colors)
		return (1);
	free (str);
	if (check_spaces(color) == 1)
		return (1);
	color_elmnt = ft_split(color, ',');
	free (color);
	if (set_floor_color(var, color_elmnt) == 1)
		return (1);
	return (0);
}

int	check_sky_color(t_var *var, char *str)
{
	int		i;
	char	*color;
	char	**color_elmnt;

	var->c_colors = malloc(sizeof(int) * 3);
	str = remove_spaces_in_begin(str);
	if (check_key_c(var) == 1)
		return (1);
	color = color_adjustement(str);
	free (str);
	if (color == NULL || !var->f_colors)
		return (1);
	color_elmnt = ft_split(color, ',');
	free (color);
	i = 0;
	while (i < 3)
	{
		if (color_elmnt[i] == NULL)
			return (1);
		var->c_colors[i] = ft_atoi(color_elmnt[i]);
		i++;
	}
	ft_free(color_elmnt);
	return (0);
}

int	check_colors(t_var *var)
{
	char	*f;
	char	*c;

	var->i = 0;
	var->ch = 0;
	while (var->map_elmnt[var->i])
	{
		f = ft_strstr(var->map_elmnt[var->i], "F");
		if (f != NULL)
		{
			var->ch++;
			if (check_floor_color(var, f) == 1)
				return (1);
		}
		c = ft_strstr(var->map_elmnt[var->i], "C");
		if (c != NULL )
		{
			var->ch++;
			if (check_sky_color(var, c) == 1)
				return (1);
		}
		var->i++;
	}
	return (0);
}
