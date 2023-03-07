/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:45 by aomman            #+#    #+#             */
/*   Updated: 2023/02/07 15:22:59 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(t_var *var)
{
	if (!var->path_so || !var->path_no || !var->path_ea || !var->path_we)
	{
		ft_putstr("Error \n- map file error\n", 2);
		return (1);
	}
	return (0);
}
