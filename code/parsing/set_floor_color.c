/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:23:47 by aomman            #+#    #+#             */
/*   Updated: 2023/03/05 14:23:48 by aomman           ###   ########.fr       */
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
