/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:25:20 by aomman            #+#    #+#             */
/*   Updated: 2023/03/03 19:32:26 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <window.h>

int	wall_text(t_window *win)
{
	int	i;
	int	j;

	win->so_text = mlx_xpm_file_to_image(win->mlx, win->path_so, &i, &j);
	if (!win->so_text)
		return (1);
	win->no_text = mlx_xpm_file_to_image(win->mlx, win->path_no, &i, &j);
	if (!win->no_text)
		return (1);
	win->ea_text = mlx_xpm_file_to_image(win->mlx, win->path_ea, &i, &j);
	if (!win->ea_text)
		return (1);
	win->we_text = mlx_xpm_file_to_image(win->mlx, win->path_we, &i, &j);
	if (!win->we_text)
		return (1);
	return (0);
}
