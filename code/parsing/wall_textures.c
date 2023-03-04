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
	t_data	data;
	int		i;
	int		j;

	win->so_text = mlx_xpm_file_to_image(win->mlx, win->path_so, &i, &j);
	if (!win->so_text)
		ft_putstr_fd("Texture failed\n", 2);
	// win->so_addr = mlx_get_data_addr(win->so_text, &data.bits_per_pixel,
	// 		&data.line_length, &data.endian);
	win->no_text = mlx_xpm_file_to_image(win->mlx, win->path_no, &i, &j);
	if (!win->no_text)
		ft_putstr_fd("Texture failed\n", 2);
	win->ea_text = mlx_xpm_file_to_image(win->mlx, win->path_ea, &i, &j);
	if (!win->ea_text)
		ft_putstr_fd("Texture failed\n", 2);
	win->ea_addr = mlx_get_data_addr(win->so_text, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	win->we_text = mlx_xpm_file_to_image(win->mlx, win->path_we, &i, &j);
	if (!win->we_text)
		ft_putstr_fd("Texture failed\n", 2);
	win->we_addr = mlx_get_data_addr(win->so_text, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	return (0);
}
