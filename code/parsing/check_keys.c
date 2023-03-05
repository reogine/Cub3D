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

int	check_number(t_var *var)
{
	if (var->s >= 2)
		return (1);
	if (var->w >= 2)
		return (1);
	if (var->n >= 2)
		return (1);
	if (var->e >= 2)
		return (1);
	if (var->e + var->s + var->w + var->n > 1
		|| var->e + var->s + var->w + var->n == 0)
		return (1);
	return (0);
}

int	check_numberof_element(t_var *var)
{
	var->s = 0;
	var->e = 0;
	var->n = 0;
	var->w = 0;
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		var->j = 0;
		while (var->map_elmnt[var->i][var->j])
		{
			if (var->map_elmnt[var->i][var->j] == 'S')
				var->s++;
			if (var->map_elmnt[var->i][var->j] == 'N')
				var->n++;
			if (var->map_elmnt[var->i][var->j] == 'W')
				var->w++;
			if (var->map_elmnt[var->i][var->j] == 'E')
				var->e++;
			var->j++;
		}
		var->i++;
	}
	if (check_number(var) == 1)
		return (1);
	return (0);
}

int	check_key_c(t_var *var)
{
	int	strlen_var;
	int	i;

	strlen_var = ft_strlen(var->map_elmnt[var->i]);
	i = 0;
	while (i < strlen_var)
	{
		if (var->map_elmnt[var->i][i] == 'C')
			i++;
		if ((var->map_elmnt[var->i][i] >= 97
			&& var->map_elmnt[var->i][i] <= 122)
			|| (var->map_elmnt[var->i][i] >= 65
			&& var->map_elmnt[var->i][i] <= 90))
			return (1);
		i++;
	}
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
			i++;
		if ((var->map_elmnt[var->i][i] >= 97
			&& var->map_elmnt[var->i][i] <= 122)
			|| (var->map_elmnt[var->i][i] >= 65
			&& var->map_elmnt[var->i][i] <= 90))
			return (1);
		i++;
	}
	return (0);
}
