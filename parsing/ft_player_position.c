/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:54:42 by aomman            #+#    #+#             */
/*   Updated: 2023/02/22 17:54:43 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	*skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			i++;
		else
			break ;
	}
	str = ft_substr(str, i, ft_strlen(str));
	return (str);
}

void	ft_find_position(t_var *var)
{
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		var->j = 0;
		while (var->map_elmnt[var->i][var->j])
		{
			if (var->map_elmnt[var->i][var->j] == 'S'
				|| var->map_elmnt[var->i][var->j] == 'E'
				|| var->map_elmnt[var->i][var->j] == 'W'
				|| var->map_elmnt[var->i][var->j] == 'N')
			{
				var->posx = var->j + 1;
				var->posy = var->i + 1;
			}
			var->j++;
		}
		var->i++;
	}
}
