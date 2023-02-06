/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/02/06 01:32:24 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	ft_put_img(t_window *w, void *img, int x, int y)
{
	mlx_put_image_to_window(w->mlx, w->win_ptr,
		img, (x * 38), (y * 38));
}

t_tileset	ft_assign_tiles(t_window *w)
{
	int		size;

	size = 38;
	w->tileset.terrain = mlx_xpm_file_to_image(w->mlx, \
		"assets/terrain.xpm", &size, &size);
	w->tileset.wall = mlx_xpm_file_to_image(w->mlx, \
		"assets/wall.xpm", &size, &size);
}
