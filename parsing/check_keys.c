/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:32:36 by aomman            #+#    #+#             */
/*   Updated: 2023/02/09 22:32:56 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	zero_check(t_var *var)
{
	if (var->map_elmnt[var->i][var->j] == '0')
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

int	ft_check(t_var *var)
{
	while (var->map_elmnt[var->i])
	{
		var->j = 0;
		while (var->map_elmnt[var->i][var->j])
		{
			if (var->map_elmnt[var->i][var->j] >= 48)
			{
				if (var->map_elmnt[var->i][var->j] != '1'
					&& var->map_elmnt[var->i][var->j] != '0'
					&& var->map_elmnt[var->i][var->j] != 'P'
					&& var->map_elmnt[var->i][var->j] != 'N')
					return (1);
				if (zero_check(var) == 1)
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

int	check_key_f(t_var *var)
{
	int	strlen_var;
	int	i;

	strlen_var = ft_strlen(var->map_elmnt[var->i]);
	i = 0;
	while (i < strlen_var)
	{
		if (var->map_elmnt[var->i][i] == 'F')
			break ;
		if (var->map_elmnt[var->i][i] > ' ')
			return (1);
		i++;
	}
	return (0);
}
