/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:25 by aomman            #+#    #+#             */
/*   Updated: 2023/02/17 09:55:35 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	pos_check(t_var *var)
{
	if (var->map_elmnt[var->i][var->j] == 'W'
		|| var->map_elmnt[var->i][var->j] == 'S'
		|| var->map_elmnt[var->i][var->j] == 'N'
		|| var->map_elmnt[var->i][var->j] == 'E'
		|| var->map_elmnt[var->i][var->j] == '0')
	{
		if (var->map_elmnt[var->i - 1] == NULL
			|| var->map_elmnt[var->i - 1][var->j] <= 32)
			return (1);
		else if (var->map_elmnt[var->i][var->j - 1] <= 32
			|| var->map_elmnt[var->i][var->j + 1] <= 32)
			return (1);
		else if (var->map_elmnt[var->i + 1] == NULL
			|| var->map_elmnt[var->i + 1][var->j] <= 32
			|| !var->map_elmnt[var->i + 1][var->j])
			return (1);
	}
	return (0);
}

int	zero_check(t_var *var)
{
	if (var->map_elmnt[var->i][0] == '0'
		|| var->map_elmnt[var->i][0] == 'S'
		|| var->map_elmnt[var->i][0] == 'N'
		|| var->map_elmnt[var->i][0] == 'W'
		|| var->map_elmnt[var->i][0] == 'E')
		return (1);
	return (0);
}

int	element_check(t_var *var)
{
	if (var->map_elmnt[var->i][var->j] != '1'
		&& var->map_elmnt[var->i][var->j] != '0'
		&& var->map_elmnt[var->i][var->j] != 'P'
		&& var->map_elmnt[var->i][var->j] != 'N'
		&& var->map_elmnt[var->i][var->j] != 'W'
		&& var->map_elmnt[var->i][var->j] != 'E'
		&& var->map_elmnt[var->i][var->j] != 'N'
		&& var->map_elmnt[var->i][var->j] != 'S')
		return (1);
	return (0);
}

int	ft_check(t_var *var)
{
	while (var->map_elmnt[var->i])
	{
		var->j = 0;
		while (var->map_elmnt[var->i][var->j])
		{
			if (var->map_elmnt[var->i][var->j] >= 48)
			{
				if (element_check(var) == 1)
					return (1);
				if (zero_check(var) == 1)
					return (1);
				if (pos_check(var) == 1)
					return (1);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	check_map_component(t_var *var)
{
	int	space;

	space = 0;
	var->i = 0;
	if (var->checker == 6)
	{
		var->i = var->checker;
		if (ft_check(var) == 1)
			return (1);
	}
	else
		return (1);
	return (0);
}
