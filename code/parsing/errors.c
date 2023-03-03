/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:38 by aomman            #+#    #+#             */
/*   Updated: 2023/02/07 15:35:02 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_errors(t_var *var, char **argv)
{
	if (check_map(var, argv) == 1)
	{
		free(var);
		return (1);
	}
	paths_valid(var);
	if (check_texture(var) == 1)
		return (1);
	if (check_colors(var) == 1)
	{
		ft_putstr("Error in map file\n", 2);
		return (1);
	}
	if (check_values(var) == 1)
	{
		ft_putstr("Error in map file\n", 2);
		return (1);
	}
	var->checker = 6;
	if (check_map_component(var) == 1)
	{
		ft_putstr("Error in map file\n", 2);
		return (1);
	}
	return (0);
}

int	check_errors2(t_var *var, char **argv)
{
	if (check_errors(var, argv) == 1)
		return (1);
	var->map_elmnt = var->map_elmnt + 6;
	if (check_numberof_element(var) == 1)
	{
		ft_putstr("Error in map file\n", 2);
		return (1);
	}
	return (0);
}
