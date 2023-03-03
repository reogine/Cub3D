/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:16:34 by aomman            #+#    #+#             */
/*   Updated: 2023/02/07 18:16:46 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_values(t_var *var)
{
	int	i;

	i = 0;
	while (i < 3)
	{	
		if (var->f_colors[i] > 255 || var->f_colors[i] < 0)
			return (1);
		if (var->c_colors[i] > 255 || var->c_colors[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

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

int	check_floor_color(t_var *var)
{
	int		i;
	char	*color;
	char	**color_elmnt;

	var->f_colors = malloc(sizeof(int) * 3);
	if (check_key_f(var) == 1)
		return (1);
	color = color_adjustement(var);
	if (color == NULL || !var->f_colors)
		return (1);
	if (check_spaces(color) == 1)
		return (1);
	color_elmnt = ft_split(color, ',');
	free (color);
	i = 0;
	while (i < 3)
	{
		if (color_elmnt[i] == NULL)
			return (1);
		var->f_colors[i] = ft_atoi(color_elmnt[i]);
		i++;
	}
	ft_free(color_elmnt);
	return (0);
}

int	check_sky_color(t_var *var)
{
	int		i;
	char	*color;
	char	**color_elmnt;

	var->c_colors = malloc(sizeof(int) * 3);
	if (check_key_c(var) == 1)
		return (1);
	color = color_adjustement(var);
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
	while (var->map_elmnt[var->i])
	{
		f = ft_strstr(var->map_elmnt[var->i], "F");
		if (f != NULL)
		{
			// free (var->map_elmnt[var->i]);
			// var->map_elmnt[var->i] = NULL;
			var->map_elmnt[var->i] = remove_spaces_in_begin(f);
			if (check_floor_color(var) == 1)
				return (1);
		}
		c = ft_strstr(var->map_elmnt[var->i], "C");
		if (c != NULL )
		{
			// free (var->map_elmnt[var->i]);
			// var->map_elmnt[var->i] = NULL;
			var->map_elmnt[var->i] = remove_spaces_in_begin(c);
			if (check_sky_color(var) == 1)
				return (1);
		}
		var->i++;
	}
	return (0);
}
